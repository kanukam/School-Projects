# Name: Kennedy Anukam
# Date: 2/29/20
# Class: CS 457
# Purpose: Creating a relational database management system
import datahelper
import queries

# set of key query words
phrases = {'update', 'select', 'delete', 'alter', 'insert'}


def main():
    print("Kennedy Anukam's relational database management system,"
          " enter .EXIT to end program")
    # Continues until exit command entered
    while True:
        line = input().rstrip()
        # Exit condition
        if line.lower() == ".exit;" or line.lower() == ".exit":
            break
        # Check if query statement in input
        elif len(line) > 0 and line.split()[0].lower() in phrases:
            queries.query(line)
        else:
            datahelper.statement(line)
    print("All done.")


if __name__ == '__main__':
    main()
