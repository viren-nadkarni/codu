create database company;

use company;

create table employee
(
	fname varchar(10), 
	minit varchar(1), 
	lname varchar(10), 
	ssn int not null, 
	bdate varchar(20), 
	address varchar(40), 
	sex varchar(1), 
	salary int, 
	superssn int, 
	dno int, 
	primary key(ssn)
);

create table department
(
	dname varchar(20), 
	dnumber int not null, 
	mgrssn int, 
	mgrstartdate varchar(20), 
	primary key(dnumber), 
	foreign key(mgrssn) references employee(ssn)
);

create table dept_locations
(
	dnumber int not null, 
	dlocation varchar(20) not null, 
	primary key(dnumber, dlocation), 
	foreign key(dnumber) references department(dnumber)
);

create table project
(
	pname varchar(20), 
	pnumber int not null, 
	plocation varchar(20), 
	dnum int, 
	primary key(pnumber), 
	foreign key(dnum) references department(dnumber)
);

create table works_on
(
	essn int not null, 
	pno int not null, 
	hours float, 
	primary key(essn, pno), 
	foreign key(essn) references employee(ssn), 
	foreign key(pno) references project(pnumber)
);

create table dependent
(
	essn int, 
	dependentname varchar(20) not null, 
	sex varchar(1), 
	bdate varchar(20), 
	relationship varchar(20), 
	primary key(essn, dependentname), 
	foreign key(essn) references employee(ssn)
);

insert into employee values('John', 'B', 'Smith', 12345789, '1965-01-09', '731 Fondren, Houston, TX', 'M', 30000, 333445555, 5);
insert into employee values('Franklin', 'T', 'Wong', 333445555, '1955-12-08', '638 Voss, Houston, TX', 'M', 40000, 888665555, 5);
insert into employee values('Alicia', 'J', 'Zelaya', 999887777, '1968-07-19', '3321 Castle Spring , TX', 'F', 25000, 987654321, 4);
insert into employee values('Jennifer', 'S', 'Wallace', 987654321, '1941-06-20', '291 Berry, Bellaire, TX', 'F', 43000, 888665555, 4);
insert into employee values('Ramesh', 'K', 'Narayan', 666884444, '1962-09-15', '975 Fire Oak, Humble, TX', 'M', 38000, 333445555, 5);
insert into employee values('Joyce', 'A', 'English', 453453453, '1972-07-31', '5631 Rice, Houston, TX', 'F', 25000, 333445555, 5);
insert into employee values('Ahmad', 'V', 'Jabbar', 987987987, '1969-03-29', '980 Dallas, Houston, TX', 'M', 25000, 987654321, 4);
insert into employee values('James', 'E', 'Borg', 888665555, '1937-11-10', '450 Stone, Houston, TX', 'M', 55000, null, 1);

insert into department values('Research', 5, 333445555, '1968-05-22');
insert into department values('Administration', 4, 987654321, '1995-01-01');
insert into department values('Headquarters', 1, 888665555, '1981-06-19');

insert into dept_locations values(1, 'Houston');
insert into dept_locations values(4, 'Stafford');
insert into dept_locations values(5, 'Bellaire');
insert into dept_locations values(5, 'Sugarland');
insert into dept_locations values(5, 'Houston');

insert into project values('ProductX', 1, 'Bellaire', 5);
insert into project values('ProductY', 2, 'Sugarland', 5);
insert into project values('ProductZ', 3, 'Houston', 5);
insert into project values('Computerization', 10, 'Stafford', 4);
insert into project values('Reorganization', 20, 'Houston', 1);
insert into project values('Newbenefits', 30, 'Stafford', 4);

insert into works_on values(12345789, 1, 32.5);
insert into works_on values(12345789, 2, 7.5);
insert into works_on values(666884444, 3, 40.0);
insert into works_on values(453453453, 1, 20.0);
insert into works_on values(453453453, 2, 20.0);
insert into works_on values(333445555, 2, 10.0);
insert into works_on values(333445555, 3, 10.0);
insert into works_on values(333445555, 10, 10.0);
insert into works_on values(333445555, 20, 10.0);
insert into works_on values(999887777, 30, 30.0);
insert into works_on values(999887777, 10, 10.0);
insert into works_on values(987987987, 10, 35.0);
insert into works_on values(987987987, 30, 5.0);
insert into works_on values(987654321, 30, 20.0);
insert into works_on values(987654321, 20, 15.0);
insert into works_on values(888665555, 20, null);

insert into dependent values(333445555, 'Alice', 'F', '1986-04-05', 'Daughter');
insert into dependent values(333445555, 'Theodore', 'M', '1983-10-25', 'Son');
insert into dependent values(333445555, 'Joy', 'F', '1958-05-03', 'Spouse');
insert into dependent values(987654321, 'Abner', 'M', '1942-02-28', 'Spouse');
insert into dependent values(12345789, 'Micheal', 'M', '1988-01-04', 'Son');
insert into dependent values(12345789, 'Alice', 'F', '1988-12-30', 'Daughter');
insert into dependent values(12345789, 'Elizabeth', 'F', '1967-05-05', 'Spouse');

alter table employee add constraint emp_fkey foreign key(dno) references department(dnumber);
alter table department add constraint mgr_fkey foreign key(mgrssn) references employee(ssn);

select * from works_on;
select * from project;
select * from dependent;
select * from dept_locations;
select * from department;
select * from employee;