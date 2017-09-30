CREATE TABLE books (
    book_isbn INT NOT NULL,
    name varchar(128),
    author_id varchar(128),
    publisher_id varchar(128),
    genre varchar(128),
    PRIMARY KEY(book_isbn,author_id,publisher_id)
);

CREATE TABLE book_desc (
    book_isbn INT NOT NULL PRIMARY KEY,
    description varchar(1000),
    no_of_pages int,
    FOREIGN KEY (book_isbn) REFERENCES books(book_isbn)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE book_quantity (
    book_isbn INT NOT NULL,
    sub_id INT,
    avail boolean,
    cust_id int,
    PRIMARY KEY(book_isbn,sub_id),
    FOREIGN KEY (book_isbn) REFERENCES books(book_isbn)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);


INSERT INTO `books` (`book_isbn`, `name`, `author_id`, `publisher_id`, `genre`) VALUES ('100', 'Harry Potter and the Philosopher\'s Stone', '500', '900', 'Fiction');
INSERT INTO `books` (`book_isbn`, `name`, `author_id`, `publisher_id`, `genre`) VALUES ('101', 'Harry Potter and the Chamber of Secrets', '500', '900', 'Fiction');
INSERT INTO `books` (`book_isbn`, `name`, `author_id`, `publisher_id`, `genre`) VALUES ('102', 'Harry Potter and the Prisoner of Azkaban', '500', '900', 'Fiction');
INSERT INTO `books` (`book_isbn`, `name`, `author_id`, `publisher_id`, `genre`) VALUES ('103', 'Harry Potter and the Goblet of Fire', '500', '900', 'Fiction');
INSERT INTO `books` (`book_isbn`, `name`, `author_id`, `publisher_id`, `genre`) VALUES ('104', 'Harry Potter and the Order of the Phoenix', '500', '900', 'Fiction');

-- Another way of inserting

INSERT INTO `book_desc` (`book_isbn`, `description`, `no_of_pages`) VALUES ('100', 'The first book of the Harry Potter series', '223'), ('101', 'The second book of the Harry Potter series', '251'), ('102', 'The third book of the Harry Potter series', '317'), ('103', 'The fourth book of the Harry Potter series', '636'), ('104', 'The fifth book of the Harry Potter series', '766');


INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('100', '01', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('100', '02', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('100', '03', '0', 300);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('100', '04', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('100', '05', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('101', '01', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('101', '02', '0', 300);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('101', '03', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('101', '04', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('101', '05', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '01', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '02', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '03', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '04', '0', 300);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '05', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('103', '01', '0', 300);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('103', '02', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('103', '03', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('103', '04', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('103', '05', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('104', '01', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('104', '02', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('104', '03', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('104', '04', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('104', '05', '0', 300);


DELETE FROM `books` WHERE `books`.`book_isbn` = 102

INSERT INTO `books` (`book_isbn`, `name`, `author_id`, `publisher_id`, `genre`) VALUES ('102', 'Harry Potter and the Prisoner of Azkaban', '500', '900', 'Fiction');
INSERT INTO `book_desc` (`book_isbn`, `description`, `no_of_pages`) VALUES ('102', 'The third book of the Harry Potter series', '317');
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '01', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '02', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '03', '1', NULL);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '04', '0', 300);
INSERT INTO `book_quantity` (`book_isbn`, `sub_id`, `avail`, `cust_id`) VALUES ('102', '05', '1', NULL);


SELECT * FROM books;
SELECT * FROM book_desc;
SELECT * FROM book_quantity;


DELETE FROM `books` WHERE `books`.`book_isbn` = 102

