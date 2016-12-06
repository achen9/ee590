.headers on
.mode column
.width 100 20 15
SELECT Title,
       NumSongs,
       Duration
FROM Album
JOIN
  (SELECT AlbumId, 
          strftime("%H:%M:%S", datetime(Round(sum(Milliseconds)/1000.0),"unixepoch")) AS Duration, 
          count(Milliseconds) AS NumSongs
   FROM Track
   GROUP BY AlbumId)
USING (AlbumId);
