.headers on
SELECT Title
FROM Album
JOIN
  (SELECT *
   FROM Track
   WHERE Milliseconds > 360000)
USING (AlbumId)
GROUP BY Title;