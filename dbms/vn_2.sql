create table account (accno int, branchname varchar(32), balance int);
create table branch (branchname varchar(32), branchcity varchar(32), assets int);
create table customer (custname varchar(32), custaddress varchar(32), custcity varchar(32));
create table depositor (custname varchar(32), accno int);
create table loan (loanno int, branchname varchar(32), amount int);
create table borrower (custname varchar(32), loanno int);


insert into account values(101,'madgaon',10000);
insert into account values(102,'ponda',12000);
insert into account values(103,'farmagudi',1500);

insert into depositor values('mr. pqr',101);
insert into depositor values('mr. xyz',102);
insert into depositor values('mr. ijk',103);

insert into loan values(401,'panaji',5000);
insert into loan values(402,'farmagudi',4600);

insert into borrower values ('mr. abc',401);
insert into borrower values ('mr. ijk',402);

insert into branch values('madgaon','goa',300000);
insert into branch values('ponda','goa',450000);
insert into branch values('panaji','goa',550000);
insert into branch values('farmagudi','goa',250000);

insert into customer values('mr. xyz','xyz address','ponda');
insert into customer values('mr. pqr','pqr address','madgaon');
insert into customer values('mr. abc','abc house','panaji');
insert into customer values('mr. ijk','ijk address','farmagudi');


select loan.loanno, loan.amount, custname from loan,borrower where loan.loanno=borrower.loanno and branchname='farmagudi';
select branchname from branch where assets > some(select min(assets) from branch where branchname='ponda');
select custname from customer where custaddress like '%building%';
select custname from depositor,account where account.accno=depositor.accno and branchname='farmagudi' order by custname;
select avg(balance)as avg1 from account where branchname='ponda';
select depositor.custname from depositor,borrower where borrower.custname=depositor.custname;
select max(balance) from account group by branchname;
select count(*) from account, depositor where account.accno=depositor.accno group by branchname;
select avg(balance) as avg1 from account group by branchname having avg(balance)>5000;
select 



select custname from account,depositor where account.accno=depositor.accno and branchname='ponda' order by custname;
select max(balance) from account group by branchname having avg(balance)>15000;
select custname from account join depositor on account.accno=depositor.accno where branchname='ponda' order by custname;
select branchname from branch where assets > some(select min(assets) from branch where branchname='panaji');



select max(balance) from account where balance in (select avg(balance) from account group by branchname);
select 
select avg(balance) as avg1 from account group by branchname having avg(balance)>1200;
