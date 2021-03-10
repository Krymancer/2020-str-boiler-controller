#include "main.h"

int main(int argc, char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Uso: controlemanual <endereco> <porta>\n");
    fprintf(stderr, "<endereco> eh o endereco IP da caldeira\n");
    fprintf(stderr, "<porta> eh o numero da porta UDP da caldeira\n");
    fprintf(stderr, "Exemplo de uso:\n");
    fprintf(stderr, "   controlemanual localhost 12345\n");
    return FAILED;
  }

  tRef = 25;   //setReferenceTemperature();
  hRef = 2.5;  //setReferenceHeight();

  port = atoi(argv[2]);
  localSocket = createLocalSocket();
  endpoint = createEndpointAddress(argv[1], port);

  pthread_t
      temperatureControlTask,
      waterLevelControlTask,
      showSensorsInfoTask,
      refreshSensorsInfoTask,
      verifyTemperatureTask,
      saveInfoToFileTask,
      temperatureAlarmTask;

  pthread_create(&temperatureControlTask, NULL, (void*)temperatureControl, NULL);
  pthread_create(&waterLevelControlTask, NULL, (void*)waterLevelControl, NULL);
  pthread_create(&showSensorsInfoTask, NULL, (void*)showSensorsInfo, NULL);
  pthread_create(&refreshSensorsInfoTask, NULL, (void*)refreshSensorsInfo, NULL);
  pthread_create(&verifyTemperatureTask, NULL, (void*)verifyTemperature, NULL);
  pthread_create(&saveInfoToFileTask, NULL, (void*)saveInfoToFile, NULL);
  pthread_create(&temperatureAlarmTask, NULL, (void*)temperatureAlarm, NULL);

  pthread_join(temperatureControlTask, NULL);
  pthread_join(waterLevelControlTask, NULL);
  pthread_join(showSensorsInfoTask, NULL);
  pthread_join(refreshSensorsInfoTask, NULL);
  pthread_join(verifyTemperatureTask, NULL);
  pthread_join(saveInfoToFileTask, NULL);
  pthread_join(temperatureAlarmTask, NULL);

  return EXIT_SUCCESS;
}