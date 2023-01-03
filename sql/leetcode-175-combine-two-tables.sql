/*
 * @Description: left join 用法
 * @LastEditors: zzh
 * @LastEditTime: 2023-01-03 22:10:23
 * @FilePath: /algo_sum/sql/leetcode-175-combine-two-tables.sql
 */
SELECT FirstName,
  LastName,
  City,
  State
FROM Person
  LEFT JOIN Address on Person.PersonId = Address.PersonId;