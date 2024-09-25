# Holberton School Interview Preparation

Welcome to the **Holberton School Interview Preparation** repository. This repository is a collection of coding challenges and projects designed to help prepare students for technical interviews, focusing on algorithmic problem-solving, coding efficiency, and understanding of various data structures and algorithms.

## Table of Contents
- [Overview](#overview)
- [Projects](#projects)
  - [Sandpiles](#sandpiles)
  - [Slide Line](#slide-line)
- [Requirements](#requirements)
- [Compilation and Testing](#compilation-and-testing)
- [Contributing](#contributing)
- [License](#license)

## Overview

This repository contains solutions to various algorithmic challenges that are typically asked during technical interviews. The challenges cover topics such as array manipulation, sandpiles, bitwise operations, and sliding puzzles, among others.

Each project is implemented in C and adheres to Holberton's code style guidelines (Betty coding style).

## Projects

### Sandpiles
**Directory:** `sandpiles`

The Sandpiles project simulates the mathematical model of a sandpile, where piles of sand are toppled when they reach a critical mass. This project involves computing the sum of two sandpiles and stabilizing them according to specific rules.

- **Key Concepts**: Arrays, matrix manipulation, toppling mechanics.
- **File**: `0-sandpiles.c`
- **Header**: `sandpiles.h`

### Slide Line
**Directory:** `slide_line`

The Slide Line project replicates the mechanics of the popular game "2048" on a single row. The task involves sliding and merging numbers either to the left or right, following specific rules when identical numbers are contiguous or separated by zeros.

- **Key Concepts**: Array manipulation, game mechanics, logic control.
- **File**: `0-slide_line.c`
- **Header**: `slide_line.h`

## Requirements

- **OS**: Ubuntu 14.04 LTS
- **Compiler**: GCC 4.8.4
- **Coding Style**: The code follows the Betty coding style.
- **Language**: C (C89 standard)
- All files should end with a new line.
- Global variables are not allowed.
- No more than 5 functions per file.

### Betty Linter

You can check the code's compliance with the Betty coding style using the following commands:

```bash
betty-style filename.c
betty-doc filename.c
