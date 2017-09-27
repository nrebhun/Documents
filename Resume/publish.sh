#!/usr/bin/env bash

USAGE="Usage: $ publish [opts] <path/to/tex-file>\n\n
-h|--help\t\tShow this message.
-d|--dry-run\t\tEnable Dry Run mode.\n
-D|-DEBUG-MODE\t\tEnable max verbosity.\n
"

BUILD=false
DRY_RUN=false
DEBUG_MODE=false
REDACTION_KEYWORD="\\address"

build() {
  cd "$(dirname "$1")" || exit
  if $DRY_RUN; then
    echo "pdflatex $1"
  else
    pdflatex "$1"
  fi
}

publish() {
  base="$(basename "$1")"
  cd "$(dirname "$1")" || exit 1
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
    echo "mkdir -p $public_path"
    echo "yes | cp -rf $initial_path/$base $public_path/"
  else
    mkdir -p "$public_path"
    cp "$initial_path/$base" "$public_filepath"
    sed -i "" "/$REDACTION_KEYWORD/d" "$public_filepath"
  fi

  if $BUILD; then
    build "$public_filepath"
  fi

  exit 0
}

for arg in "$@"; do

  case $arg in
    -h|--help)
    printf "$USAGE"
    exit 0
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
        publish "$arg"
    ;;
  esac
done
