SELECT W2.id AS Id
FROM Weather W1 
JOIN Weather W2 
ON W1.recordDate = DATE_SUB(W2.recordDate, INTERVAL 1 DAY) 
AND W1.temperature < W2.temperature;
