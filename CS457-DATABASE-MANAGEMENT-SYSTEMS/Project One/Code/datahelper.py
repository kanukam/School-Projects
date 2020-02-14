# Name: Kennedy Anukam
# Date: 1/30/20
# Class: CS 457
# Purpose: Helper module for relational database, evaluates string inputs
import os
import shutil
from pathlib import Path
start_directory = os.getcwd()


def validate(command):
    """
    This function is used to check if the string is vaalid by ending in ';'

    Parameters:
        command (string): Input of the query

    Returns:
        bool: True if the command ends with ';' otherwise False
    """
    if len(command) == 0 or command[0] == '-' or command[0] == " ":
        return False
    # Checks to see if command ends with ';'
    elif command[-1] == ";":
        return True
    # The statement is invalid as it doesnt end in ';'
    else:
        print("The statement is invalid, must end in ';'")
        return False


def statement(command):
    """
    This function is used to handle the queries put in by the user by checking
    if the statement is valid then seeing if the sqlite3 keywords are in the
    string.

    Parameters:
        command (string): Input of the query

    Returns:
        None
    """

    # Will only check for the key words in the query if the command ends in ';'
    if validate(command):
        # Goes to the create_database function if "create database"
        # in the string query
        if "create database" in command.lower():
            create_database(command)
        # Goes to the remove_database function if "drop database" in the
        # string query
        elif "drop database" in command.lower():
            remove_database(command)
        # Goes to the use_database function if "use database"
        # in the string query
        elif "use" in command.lower():
            use_database(command)
        # Goes to the create_table function if "create table"
        # in the string query
        elif "create table" in command.lower():
            create_table(command)
        # Goes to drop_table function
        elif "drop table" in command.lower():
            drop_table(command)
        # Goes to alter_table function
        elif "alter table" in command.lower():
            alter_table(command)
        elif "select" in command.lower():
            select_table(command)
        # None of the key words in the query, tells user its an invalid
        # statement.
        else:
            print("The statement is invalid, try again")


def create_database(command):
    """
    This function is used to handle the create query put in by the user, uses
    the os module to make the directory.

    Parameters:
        command (string): Input of the query

    Returns:
        None
    """

    # variable to remove the last element in the string query and the function
    # returns a list of the query string input
    temp = initial_step(command)
    # Checks to see if the query has three elements and "create" and "database"
    # are in the right position and exist
    if len(temp) == 3 and temp[0].lower() == "create" and \
            temp[1].lower() == "database":
        # mkdir throws an exception if the directory is already created
        try:
            os.mkdir(temp[2])
            print("Database " + temp[2] + " created.")
        # If an error was thrown, tell user the database already exists
        except FileExistsError:
            print("!Failed to create database " + temp[2] +
                  " because it already exists.")
    else:
        print("Invalid syntax used to create the database, try again")


def remove_database(command):
    """
    This function is used to handle the drop database query put in by the user
    uses the shutil module to remove the directory.

    Parameters:
        command (string): Input of the query

    Returns:
        None
    """
    # variable to remove the last element in the string query and the function
    # returns a list of the query string input
    temp = initial_step(command)
    # Checks to see if the query has three elements and "drop" and "database"
    # are in the right position and exist
    if len(temp) == 3 and temp[0].lower() == "drop" and \
            temp[1].lower() == "database":
        # Exception will be thrown if the database does not exist
        try:
            # Removing the directory by getting the current directory
            # and adding the inputed database name to remove it
            directory = Path(os.getcwd() + "//" + temp[2])
            shutil.rmtree(directory)
            print("Database " + temp[2] + " deleted.")
        # If an error was thrown, tell user the database does not exist
        except:
            print("!Failed to delete database " + temp[2] +
                  " because it does not exist.")
    else:
        print("Invalid syntax used to delete the database, try again")


def use_database(command):
    """
    This function is used to handle the use database query put in by the user
    uses the os module to change to the inputed database directory.

    Parameters:
        command (string): Input of the query

    Returns:
        None
    """

    # variable to remove the last element in the string query and the function
    # returns a list of the query string input
    temp = initial_step(command)
    # Checks to see if the query has two elements and "use" is in the correct
    # position
    if len(temp) == 2 and temp[0].lower() == "use":
        # Putting together the database to change to by constructing the
        # location from the command
        try:
            # To work with windows and Linux
            directory = Path(os.getcwd() + "//" + temp[1])
            os.chdir(directory)
            print("Using database " + temp[1] + ".")
        # Error thrown, tell user the database does not exist
        except:
            print("!Failed to use database " + temp[1] +
                  " because it does not exist.")
    else:
        print("Invalid syntax used to use the database, try again")


def create_table(command):
    """
    This function is used to handle the create table query put in by the user.
    uses the os module to check if the file is already created if not the
    table will be created.

    Parameters:
        command (string): Input of the query

    Returns:
        None
    """

    # variable to remove the last element in the string query and input the
    # query into a list
    temp = command[:-1].split()
    # Check to see that the user is actually in a database
    if os.getcwd() == start_directory:
        print("To create a table, use a database first")
    # Checks to see if the query has at least three
    # elements and "create" and "table" are in the correct position
    elif len(temp) > 3 and temp[0].lower() == "create" and \
            temp[1].lower() == "table":
        # To work with windows and Linux, check for file
        directory = Path(os.getcwd() + "//" + temp[2] + ".txt")
        # if the file exists already, tell the user it does
        if os.path.exists(directory):
            print("!Failed to create table " + temp[2] +
                  " because it already exists.")
        # If the table is not in the directory, create the file
        else:
            file_name = "{0}.txt".format(temp[2])
            print("Table " + temp[2] + " created.")
            # parse list of strings to get proper format
            clean_up(temp)
            # Writing variables to table by looping through string list
            with open(file_name, "w+") as f:
                for i in range(len(temp)):
                    if i == len(temp) - 1:
                        f.write('%s' % temp[i])
                    else:
                        f.write('%s ' % temp[i])
    else:
        print("Invalid syntax used to create the table, try again")


def drop_table(command):
    """
     function is used to delete a table(file) from the in use database
     directory. Accounts for if the file does not exist by telling the user.

     Parameters:
        command (string): Input of the query

     Returns:
         None
    """
    # variable to remove the last element in the string query and input the
    # query into a list
    temp = command[:-1].split()
    # Check to see that the user is actually in a database
    if os.getcwd() == start_directory:
        print("To drop a table, use a database first")
    # Checks to see if the query has at least three
    # elements and "drop" and "table" are in the correct position
    elif len(temp) == 3 and temp[0].lower() == "drop" and \
            temp[1].lower() == "table":
        # File to check for, to work with windows and linux
        directory = Path(os.getcwd() + "//" + temp[2] + ".txt")
        # If the file (table) does not exist, user gets an error message
        if not os.path.exists(directory):
            print("!Failed to delete table " + temp[2] +
                  " because it does not exist.")
        else:
            # Removing a file with os module
            os.remove(temp[2] + ".txt")
            print("Table " + temp[2] + " deleted.")
    else:
        print("Invalid syntax used to drop the table, try again")


def alter_table(command):
    """
     function is used to alter a table(file) from the in use database
     directory. Accounts for if the file does not exist by telling the user.

     Parameters:
        command (string): Input of the query

     Returns:
         None
    """
    temp = command[:-1].split()
    if os.getcwd() == start_directory:
        print("To alter a table, use a database first")
    # Checks to see if the query has at least six
    # elements and "drop" and "table" are in the correct position
    # May possibly change if more functionalities needed
    elif len(temp) == 6 and temp[0].lower() == "alter" and \
            temp[1].lower() == "table":
        # File to check for, works with windows and linux
        directory = Path(os.getcwd() + "//" + temp[2] + ".txt")
        # if the file does not exist, tell the user it does
        if not os.path.exists(directory):
            print("!Failed to alter table {0} because it does not exist.".format(temp[2]))
        else:
            # Adding to the first line of the file
            file_name = temp[2] + ".txt"
            with open(file_name) as f:
                lines = f.read().splitlines()
            lines[0] = lines[0] + " " + temp[4] + " " + temp[5]
            with open(file_name, "w") as f:
                for line in lines:
                    # Rewrite line by line
                    f.write("%s\n" % line)
            print("Table " + temp[2] + " modified.")
    else:
        print("Invalid syntax used to alter the table, try again")


def select_table(command):
    """
     function is used to select a table(file) from the in use database
     directory and print it. Accounts for if the file does not exist by
     telling the user.

     Parameters:
        command (string): Input of the query

     Returns:
         None
    """
    temp = command[:-1].split()
    if os.getcwd() == start_directory:
        print("To select a table, use a database first")
    # Checks to see if the query has four
    # elements and "select" and "from" are in the correct position
    # May possibly change if more functionalities needed
    elif len(temp) == 4 and temp[0].lower() == "select" and \
            temp[2].lower() == "from":
        # File to check for, works with windows and Linux
        directory = Path(os.getcwd() + "//" + temp[3] + ".txt")
        # if the file does not exist, tell the user it does
        if not os.path.exists(directory):
            print('!Failed to query table ' + temp[3] +
                  " because it does not exist.")
        else:
            file = temp[3] + ".txt"
            # Iterate through the lines of the text file to print the database
            with open(file) as fp:
                lines = fp.readlines()
            # First line needs to be handled differently
            j = 0
            for i in lines:
                data = i.split()
                types = ""
                if j == 0:
                    attributes_types(data)
                    j += 1
                # Loop through and print the data then " |" except for last element
                else:
                    for j in range(1, len(data)):
                        if j == len(data) - 1:
                            types += data[i]
                        # add a "| "
                        else:
                            types += data[i] + "|"
                        j += 1
                    print(temp)
    else:
        print("Invalid syntax used to select the table, try again")


def initial_step(command):
    """
    This function is used as a helper function of the queries by starting
    in the initial directory for the queries that need to start there. Also
    returns a list of strings to seperate the query by elements.

    Parameters:
        command (string): Input of the query

    Returns:
        List (string): Query seperated by the whitespaces
    """

    # Start at beginning main directory first
    os.chdir(start_directory)
    # removing the ';' from the command string
    command = command[:-1]
    # returning a list of the words to get database name
    return command.split()


def clean_up(temp):
    """
    This function is used to cleanup the query to seperate the variable names
    and data types to be inputed into the file.

    Parameters:
        temp (string): string to clean

    Returns:
        None
    """
    del temp[:3]
    # Error check to see if enough input
    if len(temp) >= 2:
        # Cleanup to remove last paranthesis
        temp[-1] = temp[-1][:-1]
        # remove first character '('
        temp[0] = temp[0][1:]
        # Loop to iterate through list and replace all occurences of ',' to ''
        for i in range(len(temp)):
            temp[i] = temp[i].replace(',', '')

def attributes_types(data_type):
    """
        This function is used to print the first line of the table which is the attributes in the correct format.
        There is two attributes the data type and the variable name so the "|" needs to be printed after the variable.

        Parameters:
            temp (data_type): attributes to print in tabular format

        Returns:
            None
        """
    temp = ""
    # Loop to construct the datatype with variable type
    for i in range(len(data_type)):
        if i == len(data_type) - 1:
            temp += data_type[i]
        #print a " | "
        elif i % 2 != 0:
            temp += data_type[i] + " | "
        else:
            temp += data_type[i] + " "
    print(temp)
