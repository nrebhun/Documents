#!/usr/bin/env python

import os, argparse, re

header_prefix = "### "
back_to_top = u'###### [\xe286910a Back to the Top]'
md_break = "\n\n"

parser = argparse.ArgumentParser()
parser.add_argument("path_to_file", help="jeeeeeeez... you didn't do it right")

args = parser.parse_args()

def generate_section(file_path = None):
    base_name = os.path.basename(file_path)
    header = assemble_header(base_name)
    content = "Full filepath: `" + file_path + "`" + md_break + "Add useful info here"

    link = linkify(base_name)

    generated_section = header + md_break + content + md_break + back_to_top + md_break + link

    return generated_section

def assemble_header(header_content = None):
    return header_prefix + header_content

def linkify(filename = None):
    link_text = "[" + filename + "]: "
    link_location = remove_specials(filename).lower()
    result = link_text + "#"+ link_location

    return result

def remove_specials(input_string = None):
    return re.sub('[/!@#$~\-\]', '', input_string)

def usage():
    path_to_file = None

    if args.path_to_file:
        print generate_section(args.path_to_file)

usage()