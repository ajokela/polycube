/**
* dynmon API generated from dynmon.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* DataplaneMetricsBase.h
*
*
*/

#pragma once

#include "../serializer/DataplaneMetricsJsonObject.h"

#include "../DataplaneMetricsOpenMetricsMetadata.h"





#include <spdlog/spdlog.h>

using namespace polycube::service::model;

class Dataplane;

class DataplaneMetricsBase {
 public:
  
  DataplaneMetricsBase(Dataplane &parent);
  
  virtual ~DataplaneMetricsBase();
  virtual void update(const DataplaneMetricsJsonObject &conf);
  virtual DataplaneMetricsJsonObject toJsonObject();

  /// <summary>
  /// Name of the metric (e.g., number of HTTP requests)
  /// </summary>
  virtual std::string getName() = 0;

  /// <summary>
  /// Corrisponding eBPF map name
  /// </summary>
  virtual std::string getMapName() = 0;

  /// <summary>
  ///
  /// </summary>
  virtual std::shared_ptr<DataplaneMetricsOpenMetricsMetadata> getOpenMetricsMetadata() = 0;
  virtual void addOpenMetricsMetadata(const DataplaneMetricsOpenMetricsMetadataJsonObject &value) = 0;
  virtual void replaceOpenMetricsMetadata(const DataplaneMetricsOpenMetricsMetadataJsonObject &conf);
  virtual void delOpenMetricsMetadata() = 0;

  std::shared_ptr<spdlog::logger> logger();
 protected:
  Dataplane &parent_;
};
