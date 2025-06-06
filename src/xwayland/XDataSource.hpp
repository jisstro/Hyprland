#pragma once

#include "../protocols/types/DataDevice.hpp"
#include <hyprutils/os/FileDescriptor.hpp>

struct SXSelection;

class CXDataSource : public IDataSource {
  public:
    CXDataSource(SXSelection&);

    virtual std::vector<std::string> mimes();
    virtual void                     send(const std::string& mime, Hyprutils::OS::CFileDescriptor fd);
    virtual void                     accepted(const std::string& mime);
    virtual void                     cancelled();
    virtual void                     error(uint32_t code, const std::string& msg);
    virtual eDataSourceType          type();

  private:
    SXSelection&             m_selection;
    std::vector<std::string> m_mimeTypes; // these two have shared idx
    std::vector<uint32_t>    m_mimeAtoms; //
};
