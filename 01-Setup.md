# Setup

## 1. Install Git and this repository

On a Linux Machine you just need to type:

	sudo apt-get install git-core

But in MacOS you need to install a package manager like [Homebrew](http://brew.sh/) for that follow this instructions

* First install Homebrew: According to their website you just need to open the terminal and type:

```bash
	ruby -e "$(curl -fsSL https://raw.github.com/Homebrew/homebrew/go/install)"
```

* Then install Git

```bash
	brew install git
```

On windows simply install git from [here](https://git-scm.com/download/win)

For GUI enthusiasts, the following softwares are available for both Windows & Mac:
- [Github Desktop Client](https://desktop.github.com/)
- [Git Karaken](www.gitkraken.com)


## 2. Make a GitHub Account and a repository for your Homework

Create a github account if you don't have one already and create a repo for the class that you'll use to submit your homework.  Name it as follows, '[YOUR_NAME]_cclab2016’. 

When you post your homework follow this rules

* **Homework should be organized in folders**: each one using the following structure: ```w[WEEK_NUMBER]_h[HOMEWORK_NUMBER]_[TITLE]```.

* **Homework should be self contain**: Inside each homework folder there should be all files needed to execute it, an HTML page using script.js or a Processing/OpenFrameworks/Arduino project.

* **Document your homework**: Each homework folder should have a ```README.md``` file where you: explain the process, doubts, changeless, discoveries, useful links, attribution of borrow code, etc.

* **Present your self**: copy and edit the```03-student_template.md``` and use it as your main ```README.md``` file on the root of your repository.

* **Avoid adding binary files**: Prevent the uploading images or executable files.

* **Keep your repository clean**: remember to add a [```.gitignore```](https://gist.github.com/ofZach/3707086). This will tells git to avoid certain files, such as compiled object code, .app / .exes, etc. It keeps your repos slim and lightweight and helps you avoid committing unnecessary things. (Beside [Zach’s gitignore](https://gist.github.com/ofZach/3707086 you can make your using [this site](http://www.gitignore.io/) ). Also you can use the one from the sims repo. For example, inside your private homework folder do:

At the end your repository should look like something like this:

```
	[YOUR NAME]_cclab2016/
       w01_h01_javascript/
           index.html
           css/
               style.css
           js/
               script.js
           README.md
       w01_h02_javascript/
           app.jas
           README.md
       w02_h01_jquery/ 
           …
           …
       w03_h01_midterm/ 
           …
       …/
       …/
       .gitignore
 ```

Once this repository is on gitHub send me the url to it.

## 3. Make a local clone of the class repo

On the directory you want to have it just do:

```bash
	git clone https://github.com/patriciogonzalezvivo/ss2015.git
	cd ss2015
	git pull && git submodule init && git submodule update && git submodule status
```

Keep it updated and use it to see each other work.

```bash
	git submodule foreach git pull origin master
```

Help and learn from others, then remember to give attribution for what you had receive.


The instructions were based on https://github.com/patriciogonzalezvivo/ss2015/blob/master/01-setup.md 