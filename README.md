# CUHK-CSCI2100-Spring26
An unofficial repo of CUHK CSCI2100B Data Structures

---

## 📖 Desciption
- This repository contains the C source codes included in the lecture slides of CSCI2100B Data Structures. The orginal codes are scattered in different slides, so I collected them and put them all into this repostiory.
- The header files are inside `include/` and the implementations are inside `src/`.
- ⚠️ I don't guarantee that these codes are 100% correct since I may make some mistakes when I copy these codes. Also, the actual codes are subject to change if you are from a different class (e.g. CSCI2100A) or attend the course after spring 2026. So, please double check before you use them in your assignments.
- I don't think using this repo is plagiarism since I only put the codes from the lecture slides into this repo. Actually, I think the lecturer should provide these codes in text files for us since it is really a pain in the ass to collect all the sources codes from the lecture slides.

## 💻 Usage
1. clone this repo
2. copy and paste the code you need
3. (optional) I also provide a simple Makefile so that you can compile all these files into a static library on Linux systems. Run `make lib` in the project root and the target file is `lib/libcsci2100.a`

## ⛔ Warning
These data structures all have serious **memory leakage** problems and lack some basic error checkings. I've pointed them out during the lectures, but the responses I got were just "we never do error checking in this course", "only a small amount of memory will be leaked"， "I tell you a secret, sometimes the OS will do nothing if you call free()" ...... Ok, what can I say

## 🤔 Suggestions for new students who want to join this course
1. This course is boring
2. You should never write C in this way in real-life
3. If you want to learn more about data structures, go to [LeetCode](https://leetcode.com/)
