x <- mean(geyser$Time)+sd(geyser$Time)*seq(-3,3,0.1) # points at which to graph the Gaussian pdf

plot(ecdf(geyser$Time), 
     verticals=TRUE, 
     pch=46, 
     main=" ",
     ylab="c.d.f.", 
     xlab="Time Between Eruptions (minutes)", 
     lwd="3", 
     col="darkblue",
     cex.axis=1.25,
     cex.lab=1.5,
     xaxs="i", 
     yaxs="i"
)

y <- pnorm (x, mean(geyser$Time), sd(geyser$Time)) # values of the Gaussian cdf

points (x, y, type="l",  lwd="3", col="darkred") # superimpose Gaussian pdf

legend("bottomright", c("Geyser c.d.f.","G(72.31,13.84) c.d.f."), fill=c("darkblue", "darkred"), cex=1.5)