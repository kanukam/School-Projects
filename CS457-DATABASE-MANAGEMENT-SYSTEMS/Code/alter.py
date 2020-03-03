# Name: Kennedy Anukam
# Date: 2/29/20
# Class: CS 457
# Purpose: alter data query
import os
from pathlib import Path
start_directory = os.getcwd()


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
    
    elif len(temp) == 6 and temp[0].lower() == "alter" and \
            temp[1].lower() == "table":
        # File to check for, works with windows and linux
        directory = Path(os.getcwd() + "//" + temp[2].upper() + ".txt")
        # if the file does not exist, tell the user it does
        if not os.path.exists(directory):
            print("!Failed to alter table {0} because it does not exist.".format(temp[2]))
        else:
            # Adding to the first line of the file
            file_name = temp[2].upper() + ".txt"
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
