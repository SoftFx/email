if(!require(devtools)) {install.packages("devtools"); library(devtools)}	
if(require(REmailSender)) {detach("package:REmailSender", unload=TRUE); remove.packages("REmailSender")}
install_github("SoftFx/email",subdir = "R/REmailSender")