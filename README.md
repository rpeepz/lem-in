# lem-in
42 project lem in

### Table Of Contents
* [Objective](#objective)
* [Installation](#installation)
* [Usage](#usage)
* [Project Structure](#project-structure)
* [Dependencies](#dependencies)
* [Subject PDF](#subject-pdf)
* [Keep In Touch](#keep-in-touch)

#### About 42  
[42][42] is a free, non profit, project-based, peer-to-peer learning coding school. It originated in France and now has over 20 campuses all over the world. More information can be found [here][42].

<br>

---

<br>


## Objective  
This projects goal is to create a "Hex" simulator.

---  


## Installation
Download and compile repo:  
``` 
git clone https://github.com/rpeepz/lem-in.git  
cd lem-in  
make  
```  
Executable `lem-in` will be created  
<br>


## Usage  
Standard Usage
```
./lem-in < [file]  
```
Usage With Vizualizer
```
./lem-in < [file] | python3 viz/viz.py
```
Make sure you have the required [dependencies](#dependencies) before proceeding.  
For instructions and/or greater detail refer to the project's [pdfs](#subject-pdf)  

<br>

---  

<br>

## Project Structure

### Source files

```
src/
├── add_edge.c
├── continue_movement.c
├── find_path.c
├── graph_undirected.c
├── lem_in.c
├── path_info.c
├── path_matrix.c
├── print.c
├── queue.c
├── reverse_array.c
├── run_ants.c
├── split_line.c
├── unvisit_neighbors.c
└── validate.c

viz/
├── ant.gif
├── dirt_large.gif
├── dirt_med.gif
├── dirt_small.gif
├── graphics.py
├── settings.py
└── viz.py

viz/
└── lemin.h

3 directories, 22 files
```

<br>

--- 

<br>

## Dependencies  
* A C language compiler most common would be GCC or Clang.
* Cmake to run the custom Makefile for fast instalation.
* Python @3.10
* Tkinter @3.10
* Code was written to run on Unix based systems, likely work on a windows machine too but is currently untested.

<br>

## Subject PDF
[Lem-in][pdf1]  

---  

## Keep in Touch  
Found a bug? Report it by contacting me on a social below  😃  
or if you feel like you can solve it, make a [pull request]!  
<br>  

You can find me on:
* [Github](https://github.com/rpeepz)  
* [Twitter](https://twitter.com/papagna94) 
* [LinkedIn](https://www.linkedin.com/in/rpapagna-510) 
<!-- * [Medium](https://medium.com/@themichaelbrave)  -->
<!-- * [Home] -->

<br>

---

_This project was attempted for learning purposes only. This repo may not be kept up to date and I cannot guarantee that it will work on your future machines. You are welcome to use and learn from this as you want, but do not implement code that you do not understand. These sources listed above have been invaluable and I advise you to do research on the subject before trying to copy the code you see here._

[42]: http://42.us.org "42 USA"
[pdf1]:  https://github.com/rpeepz/lem-in/blob/main/Lem-in.en.pdf "Lem-in"
[pull request]: https://github.com/rpeepz/lem-in/pulls "pull away"
