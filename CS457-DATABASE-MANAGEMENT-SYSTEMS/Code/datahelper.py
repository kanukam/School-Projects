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
    This function is used to check if the string is valid by ending in ';'

    Parameters:
        command (string): Input of the statement

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
    This function is used to handle the statements put in by the user by checking
    if the statement is valid then seeing if the sqlite3 keywords are in the
    string.

    Parameters:
        command (string): Input of the statement

    Returns:
        None
    """

    # Will only check for the key words in the statement if the command ends in ';'
    if validate(command):
        # Goes to the create_database function if "create database"
        # in the string statement
        if "create database" in command.lower():
            create_database(command)
        # Goes to the remove_database function if "drop database" in the
        # string statement
        elif "drop database" in command.lower():
            remove_database(command)
        # Goes to the use_database function if "use database"
        # in the string statement
        elif "use" in command.lower():
            use_database(command)
        # Goes to the create_table function if "create table"
        # in the string statement
        elif "create table" in command.lower():
            create_table(command)
        # Goes to drop_table function
        elif "drop table" in command.lower():
            drop_table(command)
        # None of the key words in the statement, tells user its an invalid
        # statement.
        else:
            print("The statement is invalid, try again")


def create_database(command):
    """
    This function is used to handle the create statement put in by the user, uses
    the os module to make the directory.

    Parameters:
        command (string): Input of the statement

    Returns:
        None
    """

    # variable to remove the last element in the string statement and the function
    # returns a list of the statement string input
    temp = initial_step(command)
    # Checks to see if the statement has three elements and "create" and "database"
    # are in the right position and exist
    if len(temp) == 3 and temp[0].lower() == "create" and \
            temp[1].lower() == "database":
        # mkdir throws an exception if the directory is already created
        try:
            os.mkdir(temp[2].upper())
            print("Database " + temp[2] + " created.")
        # If an error was thrown, tell user the database already exists
        except FileExistsError:
            print("!Failed to create database " + temp[2] +
                  " because it already exists.")
    else:
        print("Invalid syntax used to create the database, try again")


def remove_database(command):
    """
    This function is used to handle the drop database statement put in by the user
    uses the shutil module to remove the directory.

    Parameters:
        command (string): Input of the statement

    Returns:
        None
    """
    # variable to remove the last element in the string statement and the function
    # returns a list of the statement string input
    temp = initial_step(command)
    # Checks to see if the statement has three elements and "drop" and "database"
    # are in the right position and exist
    if len(temp) == 3 and temp[0].lower() == "drop" and \
            temp[1].lower() == "database":
        # Exception will be thrown if the database does not exist
        try:
            # Removing the directory by getting the current directory
            # and adding the inputed database name to remove it
            directory = Path(os.getcwd() + "//" + temp[2].upper())
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
    This function is used to handle the use database statement put in by the user
    uses the os module to change to the inputed database directory.

    Parameters:
        command (string): Input of the statement

    Returns:
        None
    """

    # variable to remove the last element in the string statement and the function
    # returns a list of the statement string input
    temp = initial_step(command)
    # Checks to see if the statement has two elements and "use" is in the correct
    # position
    if len(temp) == 2 and temp[0].lower() == "use":
        # Putting together the database to change to by constructing the
        # location from the command
        try:
            # To work with windows and Linux
            directory = Path(os.getcwd() + "//" + temp[1].upper())
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
    This function is used to handle the create table statement put in by the user.
    uses the os module to check if the file is already created if not the
    table will be created.

    Parameters:
        command (string): Input of the statement

    Returns:
        None
    """

    # variable to remove the last element in the string statement and input the
    # statement into a list
    temp = command[:-1].split()
    # Check to see that the user is actually in a database
    if os.getcwd() == start_directory:
        print("To create a table, use a database first")
    # Checks to see if the statement has at least three
    # elements and "create" and "table" are in the correct position
    elif len(temp) > 3 and temp[0].lower() == "create" and \
            temp[1].lower() == "table":
        # To work with windows and Linux, check for file
        directory = Path(os.getcwd() + "//" + temp[2].upper() + ".txt")
        # if the file exists already, tell the user it does
        if os.path.exists(directory):
            print("!Failed to create table " + temp[2] +
                  " because it already exists.")
        # If the table is not in the directory, create the file
        else:
            file_name = "{0}.txt".format(temp[2].upper())
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
        command (string): Input of the statement

     Returns:
         None
    """
    # variable to remove the last element in the string statement and input the
    # statement into a list
    temp = command[:-1].split()
    # Check to see that the user is actually in a database
    if os.getcwd() == start_directory:
        print("To drop a table, use a database first")
    # Checks to see if the statement has at least three
    # elements and "drop" and "table" are in the correct position
    elif len(temp) == 3 and temp[0].lower() == "drop" and \
            temp[1].lower() == "table":
        # File to check for, to work with windows and linux
        directory = Path(os.getcwd() + "//" + temp[2].upper() + ".txt")
        # If the file (table) does not exist, user gets an error message
        if not os.path.exists(directory):
            print("!Failed to delete table " + temp[2] +
                  " because it does not exist.")
        else:
            # Removing a file with os module
            os.remove(temp[2].upper() + ".txt")
            print("Table " + temp[2] + " deleted.")
    else:
        print("Invalid syntax used to drop the table, try again")


def initial_step(command):
    """
    This function is used as a helper function of the queries by starting
    in the initial directory for the queries that need to start there. Also
    returns a list of strings to seperate the statement by elements.

    Parameters:
        command (string): Input of the statement

    Returns:
        List (string): statement seperated by the whitespaces
    """

    # Start at beginning main directory first
    os.chdir(start_directory)
    # removing the ';' from the command string
    command = command[:-1]
    # returning a list of the words to get database name
    return command.split()


def clean_up(temp):
    """
    This function is used to cleanup the statement to seperate the variable names
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
