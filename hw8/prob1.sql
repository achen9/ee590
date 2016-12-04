.headers on
SELECT Title, Name, strftime("%M:%S",datetime(Round(Milliseconds/1000.0),"unixepoch")) 
FROM Album 
JOIN Track USING (AlbumId) 
WHERE AlbumId=
  (SELECT AlbumId 
   FROM Album 
   WHERE Title="Temple of the Dog");
