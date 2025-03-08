x = c(1,2,3,4,5)
y = c(9,10,11,12,13)
plot(x,y,type = 'l',col = 'red',main = 'comparison of x and y',xlab='x',ylab = 'y')



install.packages('ggplot2')
install.packages('plotly')
library(ggplot2)
library(plotly)

set.seed(123)
data <- data.frame(
  x = rnorm(100),
  y = rnorm(100),
  z = rnorm(100)
)

print(head(data))

plot<- ggplot(data, aes(x = x,y = y, color = z))+
  geom_point(size = 3)+
  labs(title = '2d scatter plot', x = 'x' , y = 'y' , color = 'z')+
  theme_minimal()

print(plot)

p <- plot_ly(data,x = ~x , y = ~y , z = ~z , type = 'scatter3d',mode = 'markers',marker = list(size = 3,color = ~z, colorscale = 'Viridis',symbol = 'circle')) %>%
  layout(title = '3d plot using plot_ly', 
         scene = list(xaxis = list(title = 'x axis'),
                      yaxis = list(title = 'y axis'),
                      zaxis = list(title = 'z axis')))
print(p)

empinfo <- data.frame(
  name = c("suhaani","sakshi","shivaji"),
  salary = c(1,2,3)
)

boxplot(empinfo$name ~ empinfo$salary, col = c("pink","orange"), main = "compare")




