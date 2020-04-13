# Name: Kennedy Anukam
# Date: 2/29/20
# Class: CS 457
# Purpose: Handle insert query
import os
start_directory = os.getcwd()


def insert_table(command):
    """
        function is used to insert to a table(file) from the in use database

        Parameters:
           command (string): Input of the query

        Returns:
            None
       """
    # Get query in list format
    temp = command[:-1].split()
    if os.getcwd() == start_directory:
        print("To select a table, use a database first")
    elif len(temp) >= 4 and temp[0].lower() == "insert" and temp[1].lower() == "into" and "values" in temp[3].lower():
        # Parse string to get data, getting file name before parsing
        file_name = temp[2].upper() + ".txt"
        temp = temp[3:]
        temp[0] = temp[0][7:]
        if len(temp) == 1:
            #User put in no seperations
            seperate = temp[0].split(",")
            for i in range(len(seperate)):
                seperate[i] = seperate[i].replace(',', '')
                seperate[i] = seperate[i].replace(' ', '')
                seperate[i] = seperate[i].replace("'", '')
                seperate[i] = seperate[i].replace(")", '')
            with open(file_name, "a") as f:
                # Writing to file with string of data
                f.write("\n" + ' '.join(seperate))
                print("1 new record inserted.")
        else:
            # Loop to iterate through list and replace all occurences of ',' to '' and spaces to ''
            for i in range(len(temp)):
                temp[i] = temp[i].replace(',', '')
                temp[i] = temp[i].replace(' ', '')
                temp[i] = temp[i].replace("'", '')
                temp[i] = temp[i].replace(")", '')
            try:
                with open(file_name, "a") as f:
                    # Writing to file with string of data
                    f.write("\n" + ' '.join(temp))
                    print("1 new record inserted.")
            # Error thrown if the 'table' does  not exist
            except OSError:
                print("File does not exist")
    else:
        print("Invalid syntax used to insert to the table, try again")
