.headers on
SELECT FirstName || " " || LastName AS Customer, TotalAmount
FROM Customer
JOIN
  (SELECT CustomerId, sum(Total) AS TotalAmount
   FROM Invoice
   GROUP BY CustomerId)
USING (CustomerId)
ORDER BY TotalAmount desc
LIMIT 10;
