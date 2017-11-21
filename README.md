# rEmailSender

R package for sending emails
# How to install/update it?
```
if(!require(devtools)) {install.packages("devtools"); library(devtools)}	
if(require(REmailSender)) {detach("package:REmailSender", unload=TRUE); remove.packages("REmailSender")}
install_github("SoftFx/email")	
```