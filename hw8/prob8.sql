.headers on
.mode column
SELECT Name AS Artist,
       Artist_Revenue
FROM Artist
JOIN
  (SELECT ArtistId,
          sum(AlbumRevenue) AS Artist_Revenue
   FROM Album
   JOIN
     (SELECT AlbumId,
             sum(UnitPrice*Quantity) AS AlbumRevenue
      FROM InvoiceLine
      JOIN Track
      USING (TrackId, UnitPrice)
      GROUP BY AlbumId)
   USING (AlbumId)
   GROUP BY ArtistId)
USING (ArtistId)
ORDER BY Artist_Revenue desc
LIMIT 10;
