all:
	g++ -o out vendor1.cpp -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

clean:
	rm -rf out

help:
	@echo "follow \n1. https://sandeepghai.wordpress.com/2011/08/07/linking-of-mysql-database-with-c-on-linux-machine/ \n2. http://zetcode.com/db/mysqlc/ \n3. https://dev.mysql.com/doc/dev/mysql-server/8.0.11/mysql_8h_source.html"
