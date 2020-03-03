# Name: Kennedy Anukam
# Date: 2/29/20
# Class: CS 457
# Purpose: Handle query statements

import select_q
import alter
import insert
import update
import delete_q


def query(line):
    if "select" in line.lower():
        select_q.select_data(line)
    elif "alter" in line.lower():
        alter.alter_table(line)
    elif "insert" in line.lower():
        insert.insert_table(line)
    elif "update" in line.lower():
        update.update_table(line)
    elif "delete" in line.lower():
        delete_q.delete_tuple(line)
    else:
        pass
