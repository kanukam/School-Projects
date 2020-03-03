# Name: Kennedy Anukam
# Date: 3/1/20
# Class: CS 457
# Purpose: Query method to update table
import sys
import os

start_directory = os.getcwd()


def update_table(lines):
    """
        This function is used to handle the query to update a table.
        Finds the positions of the target and replace indexes and rewrites the changes to the table.

        Parameters:
            lines (string): Query input

        Returns:
            None
        """
    # Check to see that the user is actually in a database
    if os.getcwd() == start_directory:
        print("To update a table, use a database first")
    else:
        # Reads until the ';' character is seen
        res = [lines]
        while lines[-1] != ';':
            lines = sys.stdin.readline().rstrip()
            res.append(lines)
        # Get position of target and replace data
        try:
            file_name = res[0].split()[1].upper()
            # Get index of variable name
            index1, index2 = get_index(file_name, res)
            replacement(file_name, index1, index2, res)
        except:
            print("Error")


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
    target = res[1].split()[1]
    target2 = res[2].split()[1]
    content = content.split()
    # Placement of column to update
    index1 = content.index(target) // 2
    index2 = content.index(target2) // 2
    return index1, index2


def replacement(file_name, index1, index2, res):
    """
        This function is used to replace the data according to the query update function

        Parameters:
            file_name(string): table name
            res(string): query statement
            index1(int): value to replace
            index2(int): value being checked

        Returns:
            None
    """
    # Opens file in read mode
    with open(file_name + ".txt") as f:
        # gets target data from query statement
        target = res[2].split()[3]
        # get replace data from query statement
        replace = res[1].split()[3]
        # Removes extra characters
        target = format_data(target)
        replace = format_data(replace)
        # Read lines from file into list
        temp = f.read().splitlines()
        temp = [i.split() for i in temp]
        # Pop attributes from list
        attributes = temp.pop(0)
        count = 0
        # Loop to check if index2 equals the target for every line, if it does, replaced
        for h, i in enumerate(temp):
            for k, j in enumerate(i):
                if k == index2:
                    if temp[h][k] == target:
                        temp[h][index1] = replace
                        count += 1
        # Attributes added back to first index
        temp.insert(0, attributes)
        # Rewrite file onto table
        write_file(file_name, temp)
        if count > 1:
            print("{} records modified".format(count))
        else:
            print("{} record modified".format(count))


def format_data(string):
    """
        This function removes extra characters from update statement to acquire target and replace strings

        Parameters:
            string(str): string to clean up

        Returns:
            None
        """
    string = string.replace("'", '')
    string = string.replace(";", '')
    return string


def write_file(file_name, content):
    """
        This function writes content to file

        Parameters:
            file_name(str): Table name
            content(list): File contents
        Returns:
            None
    """
    # Rewrite to file in write mode
    with open(file_name + ".txt", "w+") as g:
        for i in content:
            g.write(' '.join(i) + "\n")
