g <- read.csv('floor_graph.csv')

png("floor256.png", width=1024, height=1024, res=200)
sub = g$x<256
par(mar=c(5,3,2,2)+0.1)
plot(g$x[sub], g$floorf[sub], type="p", cex=0.5, pch='+', xlab="x", ylab='')
points(g$x[sub], g$x.a.b.c[sub], cex=1.0, col="red", pch='.')
legend(0,256,legend=c("+a+b-c","floorf"), col=c("black","red"), pch=c('+','.'))
dev.off()

png("floor8.png", width=1024, height=1024, res=200)
sub = g$x<8
par(mar=c(5,3,2,2)+0.1)
plot(g$x[sub], g$floorf[sub], type="p", cex=0.5, pch='+', xlab="x", ylab='')
points(g$x[sub], g$x.a.b.c[sub], cex=1.0, col="red", pch='.')
legend(0,7,legend=c("+a+b-c","floorf"), col=c("black","red"), pch=c('+','.'))
dev.off()
