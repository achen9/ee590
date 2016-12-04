.headers on
SELECT Track, Title AS Album, Name AS Artist
FROM Artist
JOIN
  (SELECT *
   FROM Album 
   JOIN 
     (SELECT Name AS Track, AlbumId, Milliseconds
      FROM Track 
      ORDER BY Milliseconds desc
      LIMIT 1)
   USING (AlbumId))
USING (ArtistId);