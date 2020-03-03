# Name: Kennedy Anukam
# Date: 2/29/20
# Class: CS 457
# Purpose: Selecting from database
import sys


def select_data(lines):
    """
        This function is used to handle the select query statement.

        Parameters:
            lines (string): Input of the statement

        Returns:
            None
    """
    # Selecting all from database
    if '*' in lines:
        try:
            read_file(lines)
        except:
            print("Failed to query table " + lines.split()[3][:-1] + " because it does not exist")
    # Construct the select statement until a ';' is seen
    else:
        try:
            res = [lines]
            while lines[-1] != ';':
                lines = sys.stdin.readline().rstrip()
                res.append(lines)
            file_name = res[1].split()[1].upper()
            attributes, indexes = get_attributes(file_name, res)
            check_pos = get_index(file_name, res)
            select_tuple(file_name, res, check_pos, attributes, indexes)
        except:
            print("Error")


def read_file(lines):
    with open(lines.split()[3][:-1].upper() + ".txt") as f:
        lines = f.read().splitlines()
    print_data(lines)


def print_data(lines):
    """
        This function is used to print list in tabular format

        Parameters:
            lines (string): table values

        Returns:
            None
        """
    # looping with indexes as first row needs to be printed differently
    for i, j in enumerate(lines):
        if i == 0:
            first_line(j.split())
        else:
            other_lines(j.split())


def first_line(line):
    """
        This function is used to handle the selection of the first line.

        Parameters:
            line (string): attributes of the table

        Returns:
            None
    """
    res = ""
    # Custom rules for printing first line in tabular format
    for i, j in enumerate(line):
        if i % 2 == 0:
            res += j + " "
        elif i % 2 != 0 and i != len(line) - 1:
            res += j + "|"
        else:
            res += j
    print(res)


def other_lines(line):
    """
        This function is used to handle the selection of the other lines.

        Parameters:
            line (string): attributes of the table

        Returns:
            None
    """
    res = ""
    for j, i in enumerate(line):
        res += i
        if j != len(line) - 1:
            res += '|'
    print(res)


def get_attributes(file_name, res):
    """
        This function is used to handle the query to update a table.
        Finds the positions of the target and replace indexes and rewrites the changes to the table.

        Parameters:
            file_name(string): table name
            res(string): query statement

        Returns:
            None
    """
    # Open file in read mode to get indexes of target and replace
    with open(file_name + ".txt") as f:
        content = f.readline()
    target = res[0].split()[1][:-1]
    target2 = res[0].split()[2]
    content = content.split()
    # Placement of column to update
    index1 = content.index(target) // 2
    index2 = content.index(target2) // 2
    indexes = {index1, index2}
    attributes = attributes_picker(index1, index2)
    return attributes,indexes


def get_index(file_name, res):
    """
        This function is used to handle the query to update a table.
        Finds the positions of the target and replace indexes and rewrites the changes to the table.

        Parameters:
            file_name(string): table name
            res(string): query statement

        Returns:
            None
    """
    # Open file in read mode to get indexes of target and replace
    with open(file_name + ".txt") as f:
        content = f.readline()
    target = res[2].split()[1]
    # Placement of column to update
    index = content.index(target) // 2
    return index


def select_tuple(file_name, res, index, attributes, indexes):
    """
        Create list with tuples deleted

        Parameters:
            file_name(string): table name
            res(string): query statement
            index(int): position to check in file
            attributes(set): position values to take from first line
        Returns:
            None
    """
    # Opens file in read mode
    with open(file_name + ".txt") as f:
        # gets attribute variable that needs to be checked
        check = res[2].split()[3][:-1]
        # Read lines from file into list
        temp = f.read().splitlines()
        temp = [i.split() for i in temp]
        # Pop attributes from list
        values = temp.pop(0)
        logic = res[2].split()[2]
        final = []
        # append lines that satisfy condition
        for h, i in enumerate(temp):
            for k, j in enumerate(i):
                if k == index:
                    var = temp[h][k] + " " + logic + " " + check
                    if logical_eval(temp[h][k], logic, check, var):
                        compile_line = []
                        for e, z in enumerate(i):
                            if e in indexes:
                                compile_line.append(z)
                        final.append(compile_line)
        first = []
        # putting attributes in list if they're in the set of positions
        for e, i in enumerate(values):
            if e in attributes:
                first.append(i)
        final.insert(0, first)
        # Prints list in tabular format
        for i, j in enumerate(final):
            if i == 0:
                first_line(j)
            else:
                other_lines(j)


def logical_eval(value, logic, check, var):
    """
        This function evaluates logical expressions from query statement

        Parameters:
            check(str): comparison value
            logic(str): logical operator
            value(str): table value being checked
            var(str): combined logical expression
        Returns:
            None
    """
    # Logical statement aquired from input
    if logic == '=':
        return value == check
    # All other string logical expressions can be evaluated with eval()
    else:
        return eval(var)


def attributes_picker(index1, index2):
    """
        This function puts the positions in a set of the attributes positions and variables

        Parameters:
            index1(int): position one
            index2(int): position two
        Returns:
            positions(Set): all positions
    """
    # Adds indexes and + 1 for data types
    positions = {-1}
    positions.add(2 * index1)
    positions.add((2 * index1) + 1)
    positions.add(2 * index2)
    positions.add((2 * index2) + 1)
    return positions
