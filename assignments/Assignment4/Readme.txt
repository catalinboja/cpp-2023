(English version). Scroll down for Romanian Version

You are writing a program to recover backup data for a university. You have 2 files
- john.bck which stores data for a single student, named John
- students.bck which stores data for multiple students


The binary file structure for a single student is

*all strings and dynamic char arrays are serialized based on the next rule
- 4 bytes the string size (including \0) 
- char sequence with the previous size (including \0)
- exception is the faculty field (see next)


	- serialized name (see previous rule)
	- 4 bytes for age
	- serialized program name (see previous rule)
	- faculty as a 50 chars array
	- serialized university name (see previous rule)
	- 1 byte for the boolean hasScholarship
	- 4 bytes for number of grades
	- for each grade
		- serialized course name (see previous rule)
		- 4 bytes for grade value

File structure for students.bck:

- 4 bytes - number of students in the file
- followed by each student data

	

===========================================================================
(Versiunea in Romana)

Dezvolti un program software pentru a recupera datele de rezervă ale unei universitati. Ai 2 fisiere
- john.bck care stochează date pentru un singur student, pe nume John
- students.bck care stochează date pentru mai mulți studenți

Structura fișierului binar 

*toate string-urile și sirulile dinamice de caractere sunt serializate pe baza următoarei reguli
- 4 octeți dimensiunea sirului de caractere (inclusiv \0)
- secvență de caractere cu dimensiunea anterioară (inclusiv \0)
- excepție este numele facultății (vezi în continuare)

Structura fișierului:

- 4 octeți - numărul de studenți din fișier
- urmate de datele fiecărui elev
	- nume serializat (vezi regula anterioară)
	- 4 octeți pentru vârstă
	- numele programului serializat (vezi regula anterioară)
	- facultate ca o secventa de 50 de caractere
	- nume serializat al universității (vezi regula anterioară)
	- 1 byte pentru atributul logic hasScholarship
	- 4 octeți pentru numar note
	- pentru fiecare nota
		- numele cursului serializat (vezi regula anterioară)
		- 4 octeți pentru valoarea gradului
	