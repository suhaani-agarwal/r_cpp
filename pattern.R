n = as.numeric(readline(prompt = "enter number : "))

#1
i = 1
while(i<=n){
  j = n-i
  while(j>=0){
    cat(" ")
    j=j-1
  }
  k=0
  while(k<i){
    cat("*")
    k=k+1
  }
  s=i-1
  while(s>0){
    cat("*")
    s=s-1
  }
  cat("\n")
  
  i=i+1
  
}

#1
i=1
while(i<=n){
  j=n-i
  while(j>0){
    cat(" ")
    j=j-1
  }
  k = 1
  while(k<=i){
    cat(k)
    k=k+1
  }
  s = i-1
  while(s>0){
    cat(s)
    s=s-1
  }
  cat("\n")
  i=i+1
  
}

#2
i=0
while(i<=n){
  j=n-i
  while(j>0){
    cat(" ")
    j=j-1
  }
  
  r=0
  while(r<=i){
    c = factorial(i)/(factorial(r)*factorial(i-r))
    cat(c, " ")
    r=r+1
  }
  cat("\n")
  i=i+1
}
