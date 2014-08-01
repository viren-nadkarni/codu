import sys, os
import sqlite3
import _mysql
import psycopg2

## user: postgres
## passwd: postgres
## port: 5432

def main():
    #author = input('Full name of author: ')
    author = 'William Stallings'
    
    # sqlite - db1
    conn = sqlite3.connect('db1.sqlite3')
    cur = conn.cursor()
    cur.execute('SELECT * FROM books WHERE author = \'' + author + '\';')
    result = cur.fetchone()
    print result
    
    # mysql - db2
    conn2 = _mysql.connect( host='localhost',
                            user='root',
                            passwd='',
                            db='db2')
                            
    conn2.query('SELECT * FROM authors')
    r2 = conn2.store_result()
    result2 = r2.fetch_row()
    print result2
    
    #postgresql - db3
    conn3 = psycopg2.connect( 'dbname=db3 user=postgres password=postgres')
    cur3 = conn3.cursor()
    cur.execute("INSERT INTO library VALUES ('" + str(result[1]) + "', '" + str(result[2]) + "', '" + result2[0][1] + "');")
    print 'entry inserted'
    
if __name__ == '__main__':
    main()
    