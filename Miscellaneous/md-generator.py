#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os, argparse, re

header_prefix = "### "
back_to_top = u'###### [↑ Back to the Top]'
md_break = "\n\n"

parser = argparse.ArgumentParser()
parser.add_argument("filepath", type=str,
                    help="Some filepath you'd like to generate documentation snippets for.")

args = parser.parse_args()

def generate_section(file_path = None):
    base_name = os.path.basename(file_path)
    header = assemble_header(base_name)
    content = "Full filepath: `" + file_path + "`" + md_break + "Add useful info here"

    link = linkify(file_path, base_name)

    # This needs to change, to process multi-line input.
    # Most variable assignments will simply need to be converted to array concats
    generated_section = header + md_break + content + md_break + back_to_top + md_break + link

    return generated_section

def assemble_header(header_content = None):
    return header_prefix + header_content

def linkify(file_path = None, base_name = None):
    link_text = "[" + file_path + "]: "
    link_location = remove_specials(base_name).lower()
    result = link_text + "#"+ base_name

    return result

def remove_specials(input_string = None):
    return re.sub('[/!@#$~\-]', '', input_string)

def usage():
    if args.filepath:
        print generate_section(args.filepath)

usage()