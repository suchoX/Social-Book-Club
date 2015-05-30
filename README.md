# Social-Book-Club
Social Book Club - Simple Command Line C++ Application with File Based Database Management

A basic Command Line C++ application which lets us do the following-
1. Create a New User.
2. List Books available on the basis of Book Name and Author name
3. Rate a particular book
3. Follow A user.
4. Suggest a book to read on the basis of what the users we follow and
the users they follow read.

User has to create an 'account' with user name and password and has to
'login' to do the above.

The database is simple File Based Database System, where every user,
book and author has it's own file and changes are made to these files.

The user's file name is the user name of the user which has the
information(Password, Name, DOB, Books Read)

username_follow is the file which lists the users it follows.

Each user is assigned an index for better access in the code(User Index.txt).

Some books and authors have been added.
