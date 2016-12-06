.headers on
.mode column
SELECT Name AS Track, Quantity
FROM Track 
JOIN
  (SELECT TrackId, 
          sum(Quantity) AS Quantity 
   FROM InvoiceLine
   GROUP BY TrackId)
USING (TrackId)
ORDER BY Quantity desc
LIMIT 10;
