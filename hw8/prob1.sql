.headers on
.mode column
.width 20 20 10
SELECT Title AS Album, 
       Name AS Track, 
       strftime("%M:%S", datetime(Round(Milliseconds/1000.0),"unixepoch")) AS Duration
FROM Album 
JOIN Track USING (AlbumId) 
WHERE AlbumId=
  (SELECT AlbumId 
   FROM Album 
   WHERE Title="Temple of the Dog");
