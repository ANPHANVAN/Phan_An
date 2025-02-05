-- Keep a log of any SQL queries you execute as you solve the mystery.
-- see cs50 lost    --with id = 295, y = 2024 m = 7 day = 28. at 10:15am at Humphrey Street bakery
SELECT * FROM crime_scene_reports WHERE description LIKE '%CS50%';

-- find interview at 28/7/2024. Have 7 person in this day. i find 3 person witnesses
SELECT id, name, transcript FROM interviews WHERE year = 2024 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';


-- tạo table license tình nghi tại tiệm bánh đưa ra chỉ license_plate tình nghi
CREATE TEMP TABLE license_bakery AS
WITH entrance AS (
    SELECT * FROM bakery_security_logs WHERE year = 2024 AND month = 7 AND day = 28 AND activity = 'entrance' AND (hour < 10 OR ( hour = 10 AND minute <= 15 ))
),
 exit AS (
    SELECT * FROM bakery_security_logs WHERE year = 2024 AND month = 7 AND day = 28 AND activity = 'exit' AND (hour >= 11 OR ( hour = 10 AND minute >= 15 ))
 )
SELECT e.license_plate
FROM entrance e
JOIN exit
ON e.license_plate = exit.license_plate
ORDER BY e.license_plate;


-- tạo ra tìm kiếm chuyến bay sớm  ngày 29/7/2024 -> chuyến bay flight_id = 36, bay từ fifty đi new jork
SELECT flights.*
FROM flights
JOIN airports
ON airports.id = flights.origin_airport_id
WHERE flights.year = 2024 AND flights.month = 7 AND flights.day = 29 AND flights.origin_airport_id = 8
ORDER BY flights.year, flights.month, flights.day, flights.hour


-- i found 2 the THIEF, Bruce and Taylor. So, i found 2 ACCOMPLICE is Robin, James.
SELECT bank.account_number, people.*, phone_calls.caller,phone_calls.receiver, passengers.flight_id,airports.*
FROM atm_transactions atm
JOIN bank_accounts bank
ON bank.account_number = atm.account_number
JOIN people
ON people.id = bank.person_id
JOIN license_bakery bakery
ON bakery.license_plate = people.license_plate
JOIN passengers
ON passengers.passport_number = people.passport_number
JOIN phone_calls
ON phone_calls.caller = people.phone_number
JOIN flights
ON flights.id = passengers.flight_id
JOIN airports
ON airports.id = flights.destination_airport_id
WHERE atm.year = 2024 AND atm.month = 7 AND atm.day = 28 AND atm.atm_location = 'Leggett Street' AND atm.transaction_type = 'withdraw'
    AND phone_calls.year = 2024 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <=60
    AND flights.year = 2024 AND flights.month = 7 AND flights.day = 29
    AND flights.id = 36


-- tìm đồng phạm mà thủ phạm đã gọi -> Robin and James
SELECT *
FROM people
WHERE phone_number = '(375) 8161'
