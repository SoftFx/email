#' Sending Email
#'
#'@export
SendEmail <- function(server="", login="", password="", port = 25, recipient="", subject="", body="", attachPath="") {
  dyn.load(system.file("data", "EmailSender.dll", package="REmailSender"))
  out = ""
  result = ""
  a = .C("SendEmail",server, login, password, port, recipient, subject, body, attachPath, result = out,PACKAGE = "EmailSender")$result
  dyn.unload(system.file("data", "EmailSender.dll", package="REmailSender"))
  print(a)
}
