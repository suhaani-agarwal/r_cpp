#1 suhaani agarwal
square <- function(x) {
  return(x^2)
}
num <- as.numeric(readline("Enter a number: "))
cat("The square of ", num, " is ", square(num))


#2
swap_numbers <- function(a, b) {
  temp <- a
  a <- b
  b <- temp
  return(list(a = a, b = b))
}
a <- as.numeric(readline("Enter the first number: "))
b <- as.numeric(readline("Enter the second number: "))
result <- swap_numbers(a, b)
cat("After swapping: a =", result$a, "b =", result$b)


#3
even_odd <- function(x) {
  if (x %% 2 == 0) {
    return("Even")
  } else {
    return("Odd")
  }
}
num <- as.numeric(readline("Enter a number: "))
cat("The number", num, "is", even_odd(num))


#4
decimal_to_binary <- function(x) {
  binary <- NULL
  while (x > 0) {
    binary <- c(x %% 2, binary)
    x <- x %/% 2
  }
  return(paste(binary, collapse = ""))
}
num <- as.numeric(readline("Enter a decimal number: "))
cat("The binary representation of", num, "is", decimal_to_binary(num))


#5
is_prime <- function(x) {
  if (x <= 1) {
    return(FALSE)
  }
  for (i in 2:x) {
    if (x %% i == 0) {
      return(FALSE)
    }
  }
  return(TRUE)
}
num <- as.numeric(readline("Enter a number: "))
if (is_prime(num)) {
  cat(num, "is a prime number")
} else {
  cat(num, "is not a prime number")
}

