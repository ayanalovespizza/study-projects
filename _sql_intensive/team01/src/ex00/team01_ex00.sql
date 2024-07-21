WITH LastCurrencyRates AS (
    SELECT c1.id AS currency_id,
        c1.name AS currency_name,
        c1.rate_to_usd AS last_rate_to_usd,
        c1.updated
    FROM currency AS c1
        JOIN (
            SELECT id,
                MAX(updated) AS last_updated
            FROM currency
            GROUP BY id
        ) AS last_update ON c1.id = last_update.id
        AND c1.updated = last_update.last_updated
),
AggregatedBalances AS (
    SELECT b.user_id,
        b.type,
        b.currency_id,
        SUM(b.money) AS volume
    FROM balance AS b
    GROUP BY b.user_id,
        b.type,
        b.currency_id
)
SELECT COALESCE(u.name, 'not defined') AS name,
    COALESCE(u.lastname, 'not defined') AS lastname,
    ab.type,
    ab.volume,
    COALESCE(lcr.currency_name, 'not defined') AS currency_name,
    COALESCE(lcr.last_rate_to_usd, 1) AS last_rate_to_usd,
    ab.volume * COALESCE(lcr.last_rate_to_usd, 1) AS total_volume_in_usd
FROM AggregatedBalances AS ab
    LEFT JOIN "user" u ON ab.user_id = u.id
    LEFT JOIN LastCurrencyRates AS lcr ON ab.currency_id = lcr.currency_id
ORDER BY name DESC,
    lastname,
    type;