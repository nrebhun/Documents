#!/usr/bin/env bash

USAGE="Usage: $ publish [opts] <pat/to/tex-file>\n\n
-h|--help\t\tShow this message.\n
"
BUILD=false
DRY_RUN=false
DEBUG_MODE=false
REDACTION_KEYWORD="\\address"

build() {
    cd $(dirname "$1")
    if $DRY_RUN; then
        echo "pdflatex $1"
    else
        pdflatex "$1"
    fi
}

publish() {
    base=$(basename "$1")
    cd $(dirname "$1")
    initial_path="$PWD"
    public_path="$initial_path/public"
    public_filename="${base:0:${#base}-4}p${base:${#base}-4:${#base}}"
    public_filepath="$public_path/$public_filename"

    if $DEBUG_MODE; then
        echo ">>>> Variables:"
        echo "base=$base"
        echo "initial_path=$initial_path"
        echo "public_path=$public_path"
        echo "public_filename=$public_filename"
        echo "public_filepath=$public_filepath"
        echo "sed -i \"\" \"/$REDACTION_KEYWORD/d\" \"$public_filepath\""
        echo ""
    fi

    if $DRY_RUN; then
        echo ">>>> Commands:"
        echo "mkdir $public_path"
        echo "cp $initial_path/$base $public_filepath"
    else
        mkdir $public_path
        cp $initial_path/$base $public_filepath
        sed -i "" "/$REDACTION_KEYWORD/d" "$public_filepath"
    fi

    if $BUILD; then
        build "$public_filepath"
    fi

    return 0
}

while [[ $# -gt 0 ]]; do
key="$1"

case $key in
    -h|--help)
    printf "$USAGE"
    return 0
    ;;
    -b|--build)
    BUILD=true
    echo "WILL BUILD."
    ;;
    -d|--dry-run)
    DRY_RUN=true
    echo "DRY RUN ENABLED."
    ;;
    -D|--DEBUG)
    DEBUG_MODE=true
    echo "DEBUG MODE ENABLED."
    ;;
    *)
        publish $key
    ;;
esac
shift # past argument or value
done
