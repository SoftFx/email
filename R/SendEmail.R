#' Sending Email
#'
#'@export
SendEmail <- function(server="", login="", password="", port = 25, recipient="", subject="", body="", attachPath="") {
  dyn.load(system.file("data", "EmailSender.dll", package="REmailSender"))
  out = ""
  result = ""
  attachPathes = paste(attachPath, collapse=",")
  a = .C("SendEmail",server, login, password, port, recipient, subject, body, attachPathes, result = out,PACKAGE = "EmailSender")$result
  dyn.unload(system.file("data", "EmailSender.dll", package="REmailSender"))
  print(a)
}
