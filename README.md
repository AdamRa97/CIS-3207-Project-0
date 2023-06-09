# project-0-S23
# Project 0 Spring 2023
# Unix Utilities
*Objectives:*
* Re-familiarize yourself with the C programming language 
* Re-familiarize yourself with a shell / terminal / command-line of UNIX 
* Learn (as a side effect) how to use a proper code editor such as emacs, or vi, or… 
* Learn a little about how UNIX utilities are implemented 

While the project focuses on writing simple C programs, you can see from the above that even doing so requires a bunch of other previous knowledge, including a basic idea of what a shell is and how to use the command line on some UNIX-based systems (e.g., Linux or macOS), how to use an editor such as emacs, and of course a basic understanding of C programming. If you *do not* have these skills already, this is not the right place to start (that is, do a refresh of C programming before starting the project). 

Summary of what gets turned in: 
*  A bunch of single .c files for each of the utilities below: *tuls.c*, *tucp.c*,*.* 
*  Each should compile successfully when compiled with the *-Wall* and *-Werror* flags. 
*  Each should (hopefully) meet the requirements we will discuss. 

# Part A
# tuls
The program *tuls* is a simple program. Generally, it lists information about the FILES in a directory. By default, *tuls* lists the files in the current directory. 
To invoke the program the user types:  
prompt> *./tuls*
 >    lscmd.c  
 >    a.out                        << Output from the tuls command
 >    ..  
 >    .  
  
or, 

prompt> *./tuls  direc    <*where *direc* is a directory path*>*  
>[[direc]]  
>      ->direc_1_file  
>      ->direc_2_file  
>local_1_file  
>local_2_file  
>local_3_file  
>..  
>.  
 
# Grading for Project 0 – Total 10 Points   
## Part A 5 Points   
* tuls – correctly uses the library functions scandir(), opendir(), readdir()  (1 pt) 
* tuls – correctly identifies directories vs files (0.5 pts) 
* tuls - correctly lists the current directory contents (1.5 pt)     
* tuls - correctly lists the current directory and recursively lists directory contents from the current directory (2 pts)     


# Program Details - Adam Ra
This program is created via using mainly the opendir() function and is utilized by a new function called "getDir()".

This function checks the command line arguments to make sure there are 0 or 1 arguments.

It then recursively calls through the getDir() function if there is 1 argument to print out all the files and directories of both the given directory and current working directory.

# Part B
# tucp
The second utility you will build is called **tucp**, a variant of the UNIX tool *cp*. In this project, this command is used to copy files or a group of files. It creates an exact image (copy) of a file on a disk. The *tucp* command requires at least two filenames in its arguments.  
The following are the possible command usages: 

*tucp* Sourcefile Destinationfile 
*tucp* Sourcefile Directory 
*tucp* Sourcefile-1 Sourcefile-2 Sourcefile-3 Sourcefile-n Directory 

# Details
* If the *tucp* command contains two file names, then it copies the contents of the 1st file to the 2nd file. If the 2nd file doesn’t exist, then it first creates a file with the specified name and the content of the first file is copied to it. But if the second file already exists, then it is simply overwritten without any warning. 
* If the *tucp* command has one or more arguments, specifying source file names and following those arguments, an argument specifying a directory name, then the command copies each source file to the destination directory with the same source file name. The destination file is created if did not exist, or overwritten if it already existed.
* The Linux function **stat()** can be used to determine information about a file. The **stat struct** returned by the function includes a field, **st_mode** , that can be used to determine if the path evaluated by **stat()** is a file or a directory. Use **man** to learn about the functions **stat()** and **inode()**. 

# Grading for Project 0 – Total 10 Points   
## Part A 5 Points   
* tuls – correctly uses the library functions scandir(), opendir(), readdir()  (1 pt) 
* tuls – correctly identifies directories vs files (0.5 pts) 
* tuls - correctly lists the current directory contents (1.5 pt)     
* tuls - correctly lists the current directory and recursively lists directory contents from the current directory (2 pts)     
## Part B 5 Points 
* tucp – correctly parses the command line into source and destination components (1 pt) 
* tucp - correctly copies 1 source file to a destination file (1 pt)    
* tucp – correctly copies a source file to a specified directory (1 pt)    
* tucp - correctly copies multiple source files to a specified directory. (2 pt) 



# Program Details - Adam Ra
The program is created through utilizing the fopen, fwrite, and fread functions.

A for loop iterates through the arguments to check if they're either folder of files via the stat library

It then checks for other edge cases such as if a folder exists or not via access