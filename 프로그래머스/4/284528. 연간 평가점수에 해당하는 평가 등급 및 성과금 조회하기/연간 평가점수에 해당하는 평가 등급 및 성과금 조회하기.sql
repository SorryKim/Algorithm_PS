SELECT
    EMP.EMP_NO AS EMP_NO,
    EMP.EMP_NAME AS EMP_NAME,
    GRADE.GRADE AS GRADE,
    CASE
        WHEN GRADE = 'S' THEN EMP.SAL * 0.2
        WHEN GRADE = 'A' THEN EMP.SAL * 0.15
        WHEN GRADE = 'B' THEN EMP.SAL * 0.1
        ELSE 0
    END AS BONUS
FROM 
    HR_EMPLOYEES  AS EMP
JOIN  (
        SELECT 
            EMP_NO, 
            CASE
                WHEN (SUM(SCORE) / 2) >= 96 THEN 'S'
                WHEN (SUM(SCORE) / 2) >= 90 THEN 'A'
                WHEN (SUM(SCORE) / 2) >= 80 THEN 'B'
                ELSE 'C'
            END AS GRADE
        FROM HR_GRADE
        GROUP BY EMP_NO
    ) AS GRADE
ON GRADE.EMP_NO = EMP.EMP_NO
ORDER BY EMP_NO ASC

