long long ans = 0;
for(int i = 0; i < n; i++) {
    ans = max(ans, (numTasks[i] + batchSize[i] - 1) / batchSize[i] * 1LL * processingTime[i]);
}