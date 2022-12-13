```mysql
MySQL
+ 种类：关系型（表、行、列、外键）、非关系型（对象及其属性）
DBMS（data base management system）

+ 基本命令
/*查看所有的数据库*/
show databases
/*打开指定的数据库*/
use <数据库名字>
/*查看所有的表*/
show tables
/*显示表格的信息*/
describe/desc <表名>
/*创建一个数据库*/
create databases
/*退出连接*/
exit
/*注释*/
--、#     //单行注释
/* */    //多行注释

+ 数据库的列类型
1.数值
2.字符串
3.时间日期
4.null

+ 数据库的字段属性
UnSigned --无符号，该行不能为负数
ZEROFILL --用0填充 int(3),5输出005
Auto_InCrement /*通常理解为自增，自动在上一条记录的基础上默认+1
通常用来设计唯一的主键，必须是整数类型
可定义起始值和步长
当前表设置步长(AUTO_INCREMENT=100) : 只影响当前表
SET @@auto_increment_increment=5 ; 影响所有使用自增的表(全局)
*/
NULL 与NOT NULL/*规定该列是否有值*/
DEFAULT/*用于设置默认值*/
/*拓展：
每一个表必须有五个字段
主键、乐观锁、伪删除、创建时间、修改时间*/

+ 创建一个数据库表
CREATE TABLE IF NOT EXISTS `student`(
	'字段名' 列类型 [属性] [索引] [注释],
    '字段名' 列类型 [属性] [索引] [注释],
    ......
    '字段名' 列类型 [属性] [索引] [注释]
)[表的类型][字符集设置][注释]
例：CREATE TABLE IF NOT EXISTS `student`(
	`id` INT(4)	NOT NULL AUTO_INCREMENT COMMENT '学号',
	`name` VARCHAR(30) NOT NULL DEFAULT '匿名' COMMENT '姓名',
	`pwd` VARCHAR(20) NOT NULL DEFAULT '123456' COMMENT '密码',
	`sex` VARCHAR(2) NOT NULL DEFAULT '女' COMMENT '性别',
	`birthday` DATETIME DEFAULT NULL COMMENT '出生日期',
	`address` VARCHAR(100) DEFAULT NULL COMMENT '家庭住址',
	`email` VARCHAR(50) DEFAULT NULL COMMENT '邮箱',
	PRIMARY KEY (`id`)
)ENGINE=INNODB DEFAULT CHARSET=utf8

CREATE TABLE IF NOT EXISTS `student`(
	`id` INT(4)	NOT NULL AUTO_INCREMENT COMMENT '学号',
	`name` VARCHAR(30) NOT NULL DEFAULT '匿名' COMMENT '姓名',
	`pwd` VARCHAR(20) NOT NULL DEFAULT '123456' COMMENT '密码',
	`sex` VARCHAR(2) NOT NULL DEFAULT '女' COMMENT '性别',
	`birthday` DATETIME DEFAULT NULL COMMENT '出生日期',
	`address` VARCHAR(100) DEFAULT NULL COMMENT '家庭住址',
	`email` VARCHAR(50) DEFAULT NULL COMMENT '邮箱',
	PRIMARY KEY (`id`)
)ENGINE=INNODB DEFAULT CHARSET=utf8
/*
1.表名、字段尽量用反引号括起来
2.AUTO_INCREMENT代表自增
3.所有语句后面加逗号，最后一个不加
4.主键声明放在最后，便于查看
5.MYSQL默认字符集Latin-1是单字节编码，需要设置utf8*/

+ 数据库存储引擎
INNODB/*默认使用，安全性高，支持事务处理，多表多用户操作*/
MYISAM/*节约空间，速度较快*/

+ 修改数据库
修改
修改表名 ALTER TABLE <旧表名> RENAME AS <新表名>
添加字段 ALTER TABLE <表名>ADD<字段名> 列属性[属性]
修改字段 ALTER TABLE 表名 MODIFY 字段名 列类型[属性]
ALTER TABLE 表名 CHANGE 旧字段名 新字段名 列属性[属性]
删除字段  ALTER TABLE 表名 DROP 字段名
/*例子：
-- 修改表名
-- ALTER TABLE 旧表名 RENAME AS 新表名
ALTER TABLE teacher RENAME AS teachers;

-- 增加表的字段
-- ALTER TABLE 表名 ADD 字段名 列属性
ALTER TABLE teachers ADD age INT(11);

-- 修改表的字段(重命名，修改约束)
-- ALTER TABLE 表名 MODIFY 字段名 [列属性];
ALTER TABLE teachers MODIFY age VARCHAR(11);-- 修改约束
-- ALTER TABLE 表名 CHANGE 旧名字 新名字 [列属性];
ALTER TABLE teachers CHANGE age age1 INT(1);-- 字段重命名

-- 删除表的字段
-- ALTER TABLE 表名 DROP 字段名
ALTER TABLE teachers DROP age1;*/
删除 DROP TABLE [IF EXISTS] 表名
```

```mysql
MySQL数据管理
+ 主键约束
/*主键可以唯一标识表中的记录，方便快速查找表中信息*/
语法：<字段名> <数据类型> primary key;
设置主键约束的两种方式
CREATE TABLE StuDent(
id int primary key, 
name varchar(20)
);
或
CREATE TABLE StuDent(
id int unsigned，
name varchar(20),
primary key(id)
);

+ 外键
/*如果表A的主键是表B中的字段，则该字段称为表B的外键；另外表A称为主表，表B称为从表。由此可见，外键表示了两个表之间的相关联系。以另一个表的外键作主关键字的表被称为主表（A表），具有外键的表被称为主表的从表（B表）。

在实际操作中，将A表的值放入B表来表示关联，所使用的值是A表的主键值(在必要时可包括复合主键值)。此时，B表中保存这些值的字段称为外键(foreign key)。

外键作用：

保持数据一致性，完整性，主要目的是控制存储在外键表中的数据,约束。使两张表形成关联，外键只能引用外表中的列的值或使用空值。*/
外键约束语法：
-- 在创建数据表时语法如下：
CONSTRAINT 外键名 FOREIGN KEY (从表外键字段) REFERENCES 主表 (主键字段)
-- 将创建数据表创号后语法如下：
ALTER TABLE 从表名 ADD CONSTRAINT 外键名 FOREIGN KEY (从表外键字段) REFERENCES 主表 (主键字段);
添加外键约束例子：
create table student(
id int primary key,
name varchar(20)
);/*创建学生表*/
create table class(
classid int primary key,
studentid int
);/*创建班级表*/
alter table class add constraint fk_class_studentid foreign key(studentid) references student(id);/*以学生表为主表，班级表作为副表设置外键*/
删除外键语法：
alter table 从表名 drop foreign key 外键名；
例子：
alter table class drop foreign key fk_class_studentid;

+ 唯一性约束
用于保证数据表中字段的唯一性，基本语法：字段名 数据类型 UNIQUE;
例子：create table student(
id int unique,
name varchar(20)，
);

+ 默认值约束
给数据表的某个字段指定默认值，语法：字段名 数据类型 DEFAULT 默认值；
例子：create table student(
id int,
name varchar(20),
gender varchar(10) default 'male'
);

+ 非空约束
指字段的值不能为空，语法：字段名 数据类型 NOT NULL;
例子：create table student(
id int，
name varchar(20) not null，
);

+ 自增约束
可以约束任何整数类型的字段，一般默认从1开始自增，语法：
id lNT PRIMARY KEY AUTO_INCREMENT；
例子：create table student (
id lNT PRIMARY KEY AUTO_INCREMENT,
name VARCHAR(20)，grade FLOAT
);/*自增产生的唯一的ID*/

+ DML语言
添加 insert
INSERT INTO 表名([字段1,字段2..])VALUES('值1','值2'..),[('值1','值2'..)..];
/*
1.字段之间用逗号隔开
2.字段可以省略，但是值必须一一对应
3.插入多条数据时，值要用逗号隔开*/
修改 update
UPDATE 表名 SET 字段1=值1,[字段2=值2...] WHERE 条件[];
WHERE条件语句
删除 delete
DELETE FROM 表名 [WHERE 条件]
/*InnoDB 自增列会从1开始（存在内存当中，断电即失）
MyISAM 继续从上一个子增量开始（存在内存当中，不会丢失）*/
delete 与 truncate 的区别：
前者可以加where条件，后者删除整个表但是不影响结构和索引约束；
前者不影响自增，后者归零；
前者可以回滚，后者不行。

+ 【补充】一个表允许有多个外键，且外键只适用于InnoDB表，MyISAM表不支持外键。InnoDB表和MyISAM表的主要区别是：InnoDB表支持事务、行锁和外键，MyISAM不支持；InnoDB表索引式修改效率较MyISAM高，MyISAM表查询、插入和删除效率较InnoDB高，而且MyISAM索引和数据分离，索引压缩存储，而InnoDB索引和数据紧密结合，不支持压缩，所以MyISAM内存利用率比InnoDB高；另外MyISAM的移植性也更强。
```

```mysql
查询
+ 基础查询
SELECT 查询列表 FROM 表名;
查询列表可以是表中的字段、常量、变量、表达式、函数
/*将查询列表设为*即查询所有字段*/
常数的查询
select stuid,name,'2021-03-02' from students;
过滤查询结果中的重复数据
select distinct，name from students；/*distinct关键字只在第一个列名前*/
加算术运算符的查询
select name,age+10 from students;
查询结果是一个虚拟的表格

+ 聚合函数
聚合函数使用规则：只有SELECT子句和HAVING子句、ORDER BY子句中能够使用聚合函数。例如，在WHERE子句中使用聚合函数是错误的。
sum（）	计算指定列的数值和，如果指定列类型不是数值类型则计算结果为0
avg（）	计算指定列的平均值，如果指定列类型不是数值类型则计算结果为0
max（）	计算指定列的最大值，如果指定列是字符串类型则使用字符串排序运算
min（）	计算指定列的最小值，如果指定列是字符串类型则使用字符串排序运算
count（）	统计表中数据的行数或者统计指定列其值不为NULL的数据个数
select 函数名(字段名) from 数据表名/*使用格式*/

+ 条件查询
select 查询列表 from 表名 where 筛选条件;
筛选条件：
关键字in 例子 in(8,10)/*查询字段的值为8或10的记录*/
between 10 and 18/*查询字段的值在10到18闭区间的记录*/
空值查询：is not null/*查询字段的值不为空的记录*/
like关键词：like "r%"
/*%用于匹配任意长度的字符串。例如，字符串“a%”匹配以字符a开始任意长度的字符串
_用于匹配一个任意的字符串。列入，字符串"ab_"匹配"ab"开始长度为3的字符串，如abc、abp等等..*/
limit关键词：limit 3/*限制查询结果的数量*/
select 分组函数，分组后的字段
from 表
where 筛选条件
group by 分组的字段
having 分组后的筛选
order by 排序列表
例子：-- 查询不同科目的平均分、最高分、最低分且平均分大于90
-- 核心：根据不同的课程进行分组
SELECT SubjectName,AVG(StudentResult),MAX(`StudentResult`),MIN(`StudentResult`)
FROM result r
INNER JOIN `subject` s/*引用科目表*/
on r.SubjectNo=s.SubjectNo
GROUP BY r.SubjectNo
HAVING AVG(StudentResult)>90;
distinct去重：select distinct age from students order by age;/*每个年龄只显示一条记录*/
连接查询
见下图
```

![image-20221206133534719](C:\Users\21940\AppData\Roaming\Typora\typora-user-images\image-20221206133534719.png)

```mysql
子查询
子查询是指一个查询语句嵌套在另一个查询语句内部的查询；该查询语句可以嵌套在一个 SELECT、SELECT…INTO、INSERT…INTO等语句中。在执行查询时，首先会执行子查询中的语句，再将返回的结果作为外层查询的过滤条件。
语法：select 字段 from 表名 where 字段=（select classid from students where name = Sun dasheng）
例子：select * from students where age<(select avg(age) from students);/*查询年龄小于平均年龄的学生*/
```
