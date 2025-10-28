IF NOT EXISTS (SELECT name FROM sys.databases WHERE name = N'Test')
BEGIN
    CREATE DATABASE Test;
END
GO
 
USE Test;
GO
 
IF NOT EXISTS (SELECT * FROM sys.objects WHERE name = 'Vector2')
BEGIN
    CREATE TABLE Vector2 (
        a INT,
        b INT
    );
END
GO