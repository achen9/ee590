.headers on
SELECT Name,
       sum(Duration_Minutes) AS Duration_in_Minutes
FROM Artist
JOIN
 (SELECT Title,
         Duration_Minutes,
         AlbumId,
         ArtistId
  FROM Album
  JOIN
    (SELECT AlbumId, 
            CAST(round(sum(Milliseconds)/60000.0) AS INT) AS Duration_Minutes
     FROM Track
     GROUP BY AlbumId)
  USING (AlbumId))
USING(ArtistId)
GROUP BY Name
ORDER BY sum(Duration_Minutes) desc
LIMIT 10;
