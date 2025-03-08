write.csv(mtcars, "data.csv")
data = read.csv("data.csv")
head(data)


x <- c(1, 2, 3, 4, 5)
print(x[length(x):1])


x <- c(1, 2, 3, 4, 5)
i = 1
while(i<=length(x)){
  j = 1
  while(j<length(x)){
    if(x[j+1]>x[j]){
      temp = x[j]
      x[j] = x[j+1]
      x[j+1] = temp
    }
    j = j + 1
  }
  i = i + 1
}
print(x)

x <- c(1, 2, 3, 4, 5, 6) 
evensum = 0
for(i in x){
  if(i%%2 == 0){
    evensum = evensum+i
  }
}
print(evensum)





x <- c(1, NA, 3, NA, 5)
na <- sum(is.na(x))
print(na)



second_largest <- function(x) {
  largest <- -Inf
  second_largest <- -Inf
  for (i in x) {
    if (i > largest) {
      second_largest <- largest
      largest <- i
    } else if (i>second_largest && i<largest) {
      second_largest <- i
    }
  }
  
  return(second_largest)
}

x <- c(5, 12, 8, 20, 15)
result <- second_largest(x)
print(result)


df <- data.frame(
  Name = c("John", "Alice", "Mark"),
  Age = c(22, 19, 25),
  Grade = c("A", "B", "A+")
)


new_df = df[df$Age>20,]
print(new_df)
