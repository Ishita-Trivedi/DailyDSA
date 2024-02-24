Select customer_id,count(customer_id)as count_no_trans from Visits where
visit_id not in (select visit_id from Transactions) GROUP BY customer_id;