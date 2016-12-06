.headers on
.mode column
.width 25 35 25
SELECT Track, 
       Title AS Album, 
       Name AS Artist
FROM Artist
JOIN
  (SELECT Track,
          Title,
          ArtistId
   FROM Album 
   JOIN 
     (SELECT Name AS Track, 
             AlbumId
      FROM Track 
      ORDER BY Milliseconds desc
      LIMIT 1)
   USING (AlbumId))
USING (ArtistId);
