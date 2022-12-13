### Instruction on working on git

Pushing directly to master branch is forbidden by branch control. To download the code and upload work, please follow the instructions below:

#### Download code from GitHub
1. Open Docker and Visual Studio Code.
2. Open a new terminal on vscode.
3. Run the following code in terminal:
```
git clone https://github.com/lnblanke/CS225-Final-Project.git
```
4. After downloading the code, type the following command to create your own branch (where [branch name] is name for your own branch):
```
git checkout -b [branch name]
````

#### Upload work to GitHub.
1. Open a new termial on vscode.
2. Type the following command in terminal to save changes:
```
git add .
```
3. Run the following command to commit (where [commit name] is your own name for the commit and should be about the content of the commit):
```
git commit -am "[commit name]"
```
4. Use the following command to push to the remote branch:
```
git push origin [branch name]
```
5. Open GitHub in browser and open the repo "CS225-Final-Project". Switch to the branch that you are working on.
6. There should be a notice and a button saying "compare & pull request" after you commit.
7. Follow the instruction until clicking "create pull request".
