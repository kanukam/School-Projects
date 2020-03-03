# Name: Kennedy Anukam
# Date: 3/1/20
# Class: CS 457
# Purpose: Query method to update table
import sys
import os

start_directory = os.getcwd()


def delete_tuple(lines):
    """
        This function is used to handle the query to delete tuples based on condition.
        Finds the positions of the target and doesnt copy it.

        Parameters:
            lines (string): Query input

        Returns:
            None
        """
    # Check to see that the user is actually in a database
    if os.getcwd() == start_directory:
        print("To delete tuples, use a database first")
    else:
        # Reads until the ';' character is seen
        res = [lines]
        while lines[-1] != ';':
            lines = sys.stdin.readline().rstrip()
            res.append(lines)
        # Get position of target and don't copy tuple
        try:
            file_name = res[0].split()[2].upper()
            index = get_index(file_name, res)
            remove_tuple(file_name, res, index)
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
        content = f.readline().split()
    target = res[1].split()[1]
    # Placement of column to update
    index1 = content.index(target) // 2
    return index1


def remove_tuple(file_name, res, index):
    """
        Create list with tuples deleted

        Parameters:
            file_name(string): table name
            res(string): query statement
            index(int): position to check in file
        Returns:
            None
    """
    # Opens file in read mode
    with open(file_name + ".txt") as f:
        # gets attribute variable that needs to be checked
        check = res[1].split()[3]
        check = format_data(check)
        # Read lines from file into list
        temp = f.read().splitlines()
        temp = [i.split() for i in temp]
        # Pop attributes from list
        attributes = temp.pop(0)
        count = 0
        logic = res[1].split()[2]
        final = []
        for h, i in enumerate(temp):
            add = True
            for k, j in enumerate(i):
                if k == index:
                    var = temp[h][k] + " " + logic + " " + check
                    if logical_eval(temp[h][k], logic, check, var):
                        count += 1
                        add = False
            if add:
                final.append(i)

        # Attributes added back to first index
        final.insert(0, attributes)
        # Rewrite file onto table
        write_file(file_name, final)
        if count > 1:
            print("{} records deleted".format(count))
        else:
            print("{} record deleted".format(count))


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
            temp = ' '.join(i)
            g.write("%s\n" % temp)


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
